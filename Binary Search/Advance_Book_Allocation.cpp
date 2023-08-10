/*
Qn1:- Book Allocation Problem
Condition:-
1.Each student get atleast one book
2.Each Book should be allocated to a student
3.Book alloction should be in contigious manner

You have to allocated the book to m student such that maximum no of Pages assigned to a student is minimum
ex:
10,20,30,40

10	20,30,40			max_Page=90
10,20	30,40			max_Page=70
10,20,30	40			max_Page=60
ans=60
*/
#include<iostream>
using namespace std;
bool is_possible(int arr[],int mid,int n,int m){
		int student=1;
		int page=0;
		for(int i=0;i<n;i++){
			if(page+arr[i]<=mid){
				page+=arr[i];
			}
			else{
				student++;
				if(student>m||arr[i]>mid)
					return false;
			page=arr[i];
			}
		}
	return true;
}
int book_allocation(int arr[],int sum,int n,int m){
	int start=0;
	int end=sum;
	int ans=-1;
	int mid=start+(end-start)/2;
	while(start<=end){
		if(is_possible(arr,mid,n,m)){
//			cout<<start<<" "<<mid<<" "<<end<<endl;
			ans=mid;
			end=mid-1;
		}
		else{
//				cout<<start<<" "<<mid<<" "<<end<<endl;
			start=mid+1;
		}
		mid=start+(end-start)/2;
	}
	return ans;
}
int main(){
	int n,sum=0;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
		sum+=arr[i];
	int k;
	cin>>k;
	int ans=book_allocation(arr,sum,n,k);
	cout<<ans<<endl;
	return 0;
}
