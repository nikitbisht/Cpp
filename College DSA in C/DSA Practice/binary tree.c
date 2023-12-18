//kth largest element in bst
#include<stdio.h>
#include<stdlib.h>
#define Max_Size 20
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;
node* createNode(node* newnode){
	int data;
	scanf("%d",&data);
	if(data == -1)	return NULL;
	newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	printf("\nEnter the data left of %d :- \n",newnode->data);
	newnode->left = createNode(newnode->left);
	printf("\nEnter the data right of %d :- \n",newnode->data);
	newnode->right = createNode(newnode->right);
	return newnode;
}
int inorder(node* root,int* arr){
	//moris traversal
	node* curr = root;
	int i=0;
	while(curr){
		if(!curr->left){
			printf(" %d",curr->data);
			arr[i++] = curr->data;
			curr=curr->right;
		}else{
			node* pred = curr->left;
			while(pred->right && pred->right != curr){
				pred= pred->right;
			}
			if(pred->right==NULL){
				pred->right = curr;
				curr = curr->left;
			}else{
				pred->right = NULL;
				printf(" %d",curr->data);
				arr[i++] = curr->data;
				curr = curr->right;
			}
		}
	}
	return i;
}
void insertInheap(int* arr,int* size,int val){
	*size = *size + 1;
	int index = *size;
	arr[index] = val;
	while(index > 1){
		int parent = index/2;
		if(arr[parent] > arr[index]){
			int temp = arr[parent];
			arr[parent] = arr[index];
			arr[index] = temp;
			index = parent;
		}else{
			return ;
		}
	}
}
void deletetion(int* arr,int *size){
	arr[1] = arr[*size];
	(*size)--;
	int index = 1;
	while(index < *size){
		int temp = index;
		int left  = 2*index;
		int right = 2*index+1;
		if(left < *size && arr[left] < arr[temp]){
			temp = left;
		}
		if(right < *size && arr[right] < arr[temp]){
			temp = right;
		}
		if(index != temp){
			int n = arr[temp];
			arr[temp] = arr[index];
			arr[index] = n;
			index = temp;
		}else{
			return ;
		}
	}
}
int findKthlargest(int* arr,int k,int n){
	int heap[Max_Size];
	heap[0]=-1;
	int size = 0;
	for(int i = 0;i<k;i++)
		insertInheap(heap,&size,arr[i]);
	
	for(int i = k;i<n;i++){
		if(heap[1] < arr[i]){
			deletetion(heap,&size);
			insertInheap(heap,&size,arr[i]);
		}
	}
	return heap[1];
}
int main(){
	int arr[Max_Size];
	node* root = createNode(root);
	int n = inorder(root,arr);
	int k;
	printf("Enter the value of k: ");
	scanf("%d",&k);
	for(int i = 0 ;i<n;i++){
		printf("%d ",arr[i]);
	}
	int val = findKthlargest(arr,k,n);
	printf("\nPower of heap:- %d",val);
}

//5 3 2 -1 -1 4 -1 -1 8 6 -1 -1 9 -1 -1