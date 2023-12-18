//Merge Sort
#include<stdio.h>
#define Max_Size 20
void mergeArray(int* arr,int start,int end){
	int mid = start + (end - start)/2;
	int l1 = mid - start + 1;
	int l2 = end - mid;
	int arr1[Max_Size];
	int arr2[Max_Size];
	int mainIndex = start;
	//Populating in 1st array
	for(int i = 0; i < l1; i++){
		arr1[i] = arr[mainIndex++];
	}
	mainIndex = mid + 1;
	//Populating in 2nd array 
	for(int i = 0; i < l2; i++){
		arr2[i] = arr[mainIndex++];
	}
	mainIndex = start;
	int index1 = 0;
	int  index2 = 0;
	while(index1 < l1 && index2 < l2){
		if(arr1[index1]<arr2[index2]){
			arr[mainIndex++] = arr1[index1++];
		}else{
			arr[mainIndex++] = arr2[index2++];
		}
	}
	
	while(index1 < l1){
		arr[mainIndex++] = arr1[index1++];
	}
	
	while(index2 < l2){
		arr[mainIndex++] = arr2[index2++];
	}
}
void mergeSort(int* arr,int start,int end){
	//base case
	if(start>=end)	return;
	int mid = start +(end-start)/2;
	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);
	
	mergeArray(arr,start,end);
}
int main(){
	int n;
	printf("Size of array:- ");
	scanf("%d",&n);
	int arr[Max_Size];
	printf("Enter the array element:- ");
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	mergeSort(arr,0,n-1);
	printf("\nSorted Array:- \n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}