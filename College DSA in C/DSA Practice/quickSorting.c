//Quick sort
#include<stdio.h>
#define Max_Size 20
int n;
void print(int* arr){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void swap(int *a ,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partation(int* arr,int start,int end){
	int mid = start + (end - start)/2;
	int key = arr[mid];
	int s = start;
	int e = end;
	while(s<=e){
		while(arr[s] <= key)
			s++;
		while(arr[e] > key)
			e--;
		if(s<e){
			swap(&arr[s],&arr[e]);
		}
	}
//	printf("s:- %d\te:- %d\n",s,e);
//	printf("before:- ");
//	print(arr);	
	if(s>e){
		swap(&arr[e],&arr[mid]);
	}
//	printf("After:- ");
//	print(arr);
	return e;
}
void quickSort(int* arr,int start,int end){
	//base case
	if(start>=end)	
		return;
	int part = partation(arr,start,end);
	quickSort(arr,start,part-1);
	quickSort(arr,part+1,end);
}
int main(){
	printf("Size of array:- ");
	scanf("%d",&n);
	int arr[Max_Size];
	printf("Enter the array element:- ");
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	quickSort(arr,0,n-1);
	printf("\nSorted Array:- \n");
	print(arr);
	return 0;
}