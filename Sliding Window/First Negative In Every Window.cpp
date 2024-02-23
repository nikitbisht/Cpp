#include<bits/stdc++.h>
vector<int> firstNegative(vector<int> arr, int n, int k) {
	queue<int>negative;
	vector<int>ans;
	int i=0;
	int j=0;
    while (j < n) {
		if(arr[j] < 0){
			negative.push(arr[j]);
		}	
		//check for window size
		if(j-i+1 < k){
			j++;
		}else{
			if(negative.size() == 0){
				ans.push_back(0);
			}else{
				ans.push_back(negative.front());
        //maintain window
				if(arr[i] == negative.front()){
					negative.pop();
				}
			}
			i++,j++;
		}
	}
	return ans;
}
