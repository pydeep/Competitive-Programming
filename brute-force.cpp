#include<bits/stdc++.h>
using namespace std;

int bruteSearch(string n, string m) {
		int count = 0;
		int newsize = n.size() - m.size();
		
		
		for(int i=0; i<=newsize; i++) {
				int j=0;
				 while(j<m.size() && n[i+j]==m[j]) {
				 	j++;
				 }

				 if(j==m.size()) cout<<"found";
			
		}

		
		return -1;
		

}

int main() {
 
bruteSearch("my name is pradeep yadav", "pradeep yadav");
return 0;
}
