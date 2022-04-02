{!REQUIRESCRIPT('/soap/ajax/48.0/connection.js')}
{!REQUIRESCRIPT('/soap/ajax/48.0/apex.js')}

var records = {!GETRECORDIDS($ObjectType.Payment__c)};

var result = sforce.connection.query("SELECT Id FROM PermissionSetAssignment WHERE PermissionSet.Name IN ('Upper_Level_Payment_Processor', 'BP_Credit_Card_Recon') AND AssigneeId = '{!$User.Id}'");

if(records.length<1){
	alert("{!$Label.Payment_Record_Select}");
}
else if(result.size==1){	
	var SelectedIds = ''; 
	var clientUpdate = [];
	for(var i=0;i<records.length; i++) {
		SelectedIds += "'" + records[i] + "',";
	}
	SelectedIds = SelectedIds.substring(0,SelectedIds.length - 1);
	function cursorWait(){
		document.body.style.cursor = 'wait';
	}

	function cursorClear(){
		document.body.style.cursor = 'default';
	}

	var strQuery = "Select Id, Merchant_Name__c, Client__r.Pay_Claims_to_Parent__c, Client__r.Parent.CCD_Merchant_Name__c, Client__r.ParentId, Client__c, Client__r.Name, Client__r.CCD_Merchant_Name__c From Payment__c Where Id In("+SelectedIds+")";

	var queryRecord = sforce.connection.query(strQuery);

	var sure = confirm("{!$Label.No_Of_Selected_Payment_Records}"+' '+records.length+' '+"{!$Label.Confirm_For_Selected_Payment_Records}");

	if(sure){
		try{
			cursorWait();
			if(queryRecord.size==1){
				if(queryRecord.records.Merchant_Name__c!=null && queryRecord.records.Client__c!=null) {
					var IsCheck = (queryRecord.records.Client__r.Pay_Claims_to_Parent__c==='true');
					if(IsCheck) {
						var acc = new sforce.SObject("Account");
						acc.Id = queryRecord.records.Client__r.ParentId;
						acc.CCD_Merchant_Name__c = queryRecord.records.Merchant_Name__c;
						clientUpdate.push(acc);	
					}
					else{
						var acc = new sforce.SObject("Account");
						acc.Id = queryRecord.records.Client__c;
						acc.CCD_Merchant_Name__c = queryRecord.records.Merchant_Name__c;
						clientUpdate.push(acc);		
						
					}
				}
				else if(queryRecord.records.Merchant_Name__c===null || queryRecord.records.Merchant_Name__c===undefined ){
					cursorClear();
					alert("{!$Label.Payment_Record_With_Merchant_Name}");	
				}
			}
			else{
				for(var i=0; i<queryRecord.size; i++){
					if(queryRecord.records[i].Merchant_Name__c!=null && queryRecord.records[i].Client__c!=null){
						var IsCheck = (queryRecord.records[i].Client__r.Pay_Claims_to_Parent__c==='true');
						if(IsCheck) {
							var acc = new sforce.SObject("Account");
							acc.Id = queryRecord.records[i].Client__r.ParentId
							acc.CCD_Merchant_Name__c = queryRecord.records[i].Merchant_Name__c;
							clientUpdate.push(acc);	
						}
						else{
							var acc = new sforce.SObject("Account");
							acc.Id = queryRecord.records[i].Client__c;
							acc.CCD_Merchant_Name__c = queryRecord.records[i].Merchant_Name__c;
							clientUpdate.push(acc);		
						}
					}
					else if(queryRecord.records[i].Merchant_Name__c===null || queryRecord.records[i].Merchant_Name__c===undefined){
						cursorClear();
						alert("{!$Label.Payment_Record_With_Merchant_Name}");	
						clientUpdate=[];
						break;
					}
				}
				
			}
			if(clientUpdate.length>0){
				var accResult = sforce.connection.update(clientUpdate);
				cursorClear();
				window.location.reload();
			}
			else{
				cursorClear();
			}
			
		}
		catch(e){
			cursorClear();
			alert(e);
		}
	}
}
else{
	alert("{!$Label.Insufficient_privileges_to_Update_the_CCD_Merchant_Name}");
}