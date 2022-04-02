// #include<bits/stdc++.h>
// using namespace std;
// void foursum(vector<int> &nums, int target) {
// 	sort(nums.begin(), nums.end());
// 	for(auto i=nums.begin(); i<nums.end(); i++) {
// 		cout<<*i;
// 	}
// 	//vector<vector<int>> vres;
// 	for(int i=0; i<nums.size()-3; i++) {
// 		if(i>0 && (nums[i]==nums[i-1])) continue;
// 		for(int j=i+1; j<nums.size()-2; j++){
// 			if(j>0 && (nums[j]==nums[j-1])) continue;
// 			int  kleft=j+1, kright=nums.size()-1;
// 			while(kleft<kright){
// 				if((nums[kleft]+nums[kright]+nums[i]+nums[j])==target) {
// 					// vector<int> vtemp;
// 					// vtemp.push_back(nums[i]);
// 					// vtemp.push_back(nums[j]);
// 					// vtemp.push_back(nums[kleft]);
// 					// vtemp.push_back(nums[kright]);
// 					// vres.push_back(vtemp);
// 				}
// 				else if((nums[kleft] + nums[kright])<0) {
// 					kleft++;
// 				}
// 				else {
// 					kright--;
// 				}
// 			}
// 		}
// 	}
// 	// for(auto &v1 : vres) {
// 	// 	for(auto v2 : v1) {
// 	// 		cout<<v2;
// 	// 	}
// 	// }
	
// }
// int main() {
// 	vector<int> v1 = {1,0,-1,0,-2,2};
// 	int target = 0;
// 	foursum(v1, target);
// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> foursum(vector<int> &v1, int restarget) {
	sort(v1.begin(), v1.end());
	vector<vector<int>> res;

	for(int i=0; i<v1.size()-3; i++) {
		if(i>0 && v1[i]==v1[i-1]) continue;
		for(int j=i+1; j<v1.size()-2; j++) {
			if(j>0 && v1[j]==v1[j-1]) continue;
			int low = j+1, high = v1.size()-1;
			while(low<high) {
				if((v1[i]+v1[j]+v1[low]+v1[high])==restarget) {
					vector<int> temp;
					temp.push_back(v1[i]);
					temp.push_back(v1[j]);
					temp.push_back(v1[low]);
					temp.push_back(v1[high]);

					res.push_back(temp);
					while(low<high && (v1[low]==v1[low+1])) low++;
					while(low<high && (v1[high]==v1[high-1])) high--;

					low++, high--;
				}
				else if((v1[low]+v1[high]+v1[j]+v1[i])<restarget) {
					low++;
				}
				else {
					high--;
				}
			}
		}
	}


	return res;
}

int main() {
	vector<int> v1 = {1,0,-1,0,-2,2};
	int target = 0;
	vector<vector<int>> res = foursum(v1, target);
	for(auto &resfor : res) {
		for(auto res1 : resfor) {
			cout<<res1;
		}
	}
	return 0;
}
