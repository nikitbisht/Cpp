/*
Qn:- Search in the sorted rotated array
Ex:- n=5
{1,2,3,8,9}
pivot:- {8,9,1,2,3}
key=2
O/p:- 3
*/
#include<iostream>
using namespace std;
//Search
int binary(int arr[],int s,int e,int key){
	int start=s,end=e-1;
	int mid=start+(end-start)/2;
	while(start<=end){
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]<key)
			start=mid+1;
		else
			end=mid-1;
		mid=start+(end-start)/2;
	}
	return mid;
}
//Pivot
int pivot(int arr[],int n ){			
	int start=0;
	int end=n-1;
	int mid=start+(end-start)/2;
	while(start<end){
		if(arr[0]<=arr[mid]){
			start=mid+1;
		}
		else
			end=mid;				
		mid=start+(end-start)/2;
	}
	return start;
}
//Index
int index(int arr[],int n,int key ){			
	int index=0;
	int p=pivot(arr,n);				//calling pivot
	if(arr[p]<=key&&key<=arr[n-1])
		index=binary(arr,p,n,key);	//calling for search
	else
		index=binary(arr,0,p,key);
	return index;
}

int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int key;
	cin>>key;
	int ans=index(arr,n,key);
	cout<<ans<<endl;
	return 0;
}
/*
class Solution {
    private:
        int pivot(vector<int>nums){
            int s=0;
            int e=nums.size()-1;
            int mid=s+(e-s)/2;
            while(s<=e){
                if(nums[0]<=nums[mid])
                    s=mid+1;
                else
                    e=mid;
                mid=s+(e-s)/2;
            }
            return s;
        }
        int binarysearch(vector<int>nums,int st,int en,int target){
            int s=st;
            int e=en-1;
            int mid=s+(e-s)/2;
            while(s<=e){
                if(nums[mid]==target){
                    return mid;
                }
                else if(nums[mid]<target){
                    s=mid+1;
                }
                else 
                    e=mid-1;
                mid=s+(e-s)/2;
            }
            return -1;
        }
public:
    int search(vector<int>& nums, int target) {
        int p=pivot(nums);
        int n=nums.size();
        if(target>=nums[p]&&target<=nums[n-1])
            return binarysearch(nums,p,n,target);
        else
            return binarysearch(nums,0,p,target);
    }
};
