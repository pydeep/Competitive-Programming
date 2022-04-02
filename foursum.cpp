#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> foursum(vector<int> &nums, int target) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	set<vector<int>> resdup;
	for(int i=0; i<nums.size()-3; i++) {
		// if(i>0 && v1[i]==v1[i-1]) continue;
		for(int j=i+1; j<nums.size()-2; j++) {
			// if(j>0 && v1[j]==v1[j-1]) continue;
			int low = j+1, high = nums.size()-1;
			string s = to_string(nums[i])+","+to_string(nums[j])+","+to_string(nums[low])+","+to_string(nums[high]);
			while(low<high) {	
				if((nums[i]+nums[j]+nums[low]+nums[high])==target) {
					
					
					 resdup.insert({nums[i], nums[j], nums[low], nums[high]});
					// while(low<high) if((v1[i]+v1[j]+v1[low]+v1[high])<0) low++; 
				 //    while(low<high) if((v1[i]+v1[j]+v1[low]+v1[high])>0) high--;
				    low++, high--;
				}
				else if((nums[low]+nums[high]+nums[j]+nums[i])<target) {
					low++;
				}
				else {
					high--;
				}
			}
		}
	}
	cout<<"\n";
	for(auto i=resdup.begin(); i!=resdup.end(); i++) {
		res.push_back(*i);
	}


	return res;
}

int main() {
	vector<int> v1 = {-2,-1,-1,1,1,2,2};
	int target = 0;
	vector<vector<int>> res = foursum(v1, target);
	cout<<"\n";
	for(auto &resfor : res) {
		for(auto res1 : resfor) {
			cout<<res1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
