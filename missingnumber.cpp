#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int result;
         for(int i=0; i<nums.size(); i++) {
           if(nums[i]!=i && i>0) {
               result = i;
               return result;
           }
           else if(i==nums.size()-1 && nums[nums.size()-1]!=nums.size()) {
                result = nums.size();
                return result;
           }

        }

        return -1;
}

int main() {
	vector<int> v1 = {9,6,4,2,3,5,7,0,1};
	int res = missingNumber(v1);
	cout<<res;
	return 0;
}