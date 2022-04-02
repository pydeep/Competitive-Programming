#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////Twopointer approach/////////////////////////
//twosum 
// void twosum(vector<int> res, int rtarget) {
// 	sort(res.begin(), res.end());
// 	vector<int> v2res;
// 	// for(int i=0; i<res.size()-1; i++) {
// 		int left = 0;
// 		int right = res.size()-1;

// 		while(left<right) {
		
// 				if(res[left]+res[right]==rtarget) {
// 					v2res.push_back(left);
// 					v2res.push_back(right);
// 					break;
// 				}
// 				else if(res[left]+res[right]<rtarget) {
// 					left++;
// 				}
// 				else {
// 					right--;
// 				}
// 		}

// 		for(auto &vres : v2res) {
// 			cout<<vres;
// 		}

// }
//three sum
vector<vector<int>> threesum(vector<int> res, int rtarget) {
	sort(res.begin(), res.end());
	vector<vector<int>> v2res;
	if(res.size()==0 || res.size()==1) {
		return v2res;
	}
	for(int i=0; i<res.size()-2; i++) {
		if(i==0 || (i>0 && res[i]!=res[i-1])) {
			int left = i+1;
			int right = res.size()-1;
			int sum = 0 - res[i];
			while(left<right) {
				if((res[left]+res[right])==sum) {
					v2res.push_back({res[i], res[left], res[right]});
					while(left<right && (res[left]==res[left+1])) left++;
					while(left<right && (res[right]==res[right-1])) right--;
					left++, right--;	
				} 
				else if(res[left]+res[right]<sum) {
					left++;
				}
				else {
					right--;
				}
			}	
		}
	}
	
	return v2res;
	

	for(auto i=v2res.begin(); i!=v2res.end(); i++) {
		for(auto j=i->begin(); j<i->end(); j++) {
			cout<<*j;
		}
	}
}

int main() {
	vector<int> v1 = {};
	int target = 0;
	vector<vector<int>> v2res = threesum(v1, target);

	for(auto i=v2res.begin(); i!=v2res.end(); i++) {
		for(auto j=i->begin(); j<i->end(); j++) {
			cout<<*j;
		}
	}
	
	return 0;
}
