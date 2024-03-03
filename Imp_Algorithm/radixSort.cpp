#include<iostream>
#define maxSize 100
using namespace std;
int findMaxi(int* arr,int n){
	int maxi = INT_MIN;
	for(int i=0; i<n; i++){
		maxi = max(arr[i],maxi);
	}
	return maxi;
}
void countSort(int* arr,int n,int posi){

	//create Frequency array
	int freq[10] = {0};
	for(int i=0; i<n; i++){
		freq[(arr[i]/posi)%10]++;
	}
	//Calcuate cummulative frequency
	for(int i=1; i<10; i++){
		freq[i] += freq[i-1];
	}
	
	int ans[n];
	for(int i = n-1; i>=0; i--){
		ans[--freq[(arr[i]/posi)%10]] = arr[i];
	}
	//copy into original ans
	for(int i=0; i<n; i++){
		arr[i] = ans[i];
	}
}
int main() {
    int n;
    cout<<"Size of array:- "<<endl;
    cin>>n;
    int arr[maxSize];
    cout<<"Enter Array Element:- "<<endl;
    for(int i=0; i<n; i++){
    	cin>>arr[i];
	}
	//find max element
	int maxi = findMaxi(arr,n);
	cout<<"Array Element After Radix Sort:- "<<endl;
	for(int posi = 1; maxi/posi > 0; posi *= 10){
		countSort(arr,n,posi);
	}
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
    return 0;
}
