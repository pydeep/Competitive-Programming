#include<bits/stdc++.h>
using namespace std;

void HousingProblem(vector<int> &v1, int k) {

		int i=0;
		int j=0;
		int curr = 0;
		int n = v1.size();
		while(j<n) {

			curr+=v1[j];
			j++;

		while(i<j && curr>k) {
			curr-=v1[i];
			i++;
		}

		if(curr==k) {
			cout<<i<<" "<<j-1;
		}
	} 
}

int main() {
	vector<int> v1 = {1,3,2,1,4,1,3,2,1,1};
	HousingProblem(v1, 8);
	return 0;
}