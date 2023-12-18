//GRAPH
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max_Size 10
typedef struct node{
	int data;
	struct node* next;
}node;

typedef struct graph{
	node* vertices[Max_Size];
}graph;
graph* createGraph(graph* g){
	g = (graph*)malloc(sizeof(graph));
	for(int i = 0;i<Max_Size;i++){
		g->vertices[i] = NULL;
	}
	return g;
}
void addEdge(graph* g,int start,int end ,bool flag){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = end;
	newnode->next = g->vertices[start];
	g->vertices[start] = newnode;
	if(!flag){
		return;
	}
	newnode = (node*)malloc(sizeof(node));
	newnode->data = start;
	newnode->next = g->vertices[end];
	g->vertices[end]=newnode;
}
void takeInput(graph* g){
	int n;
	printf("Enter the no of edge:- ");
	scanf("%d",&n);
	int flag,start,end;
	for(int i = 0 ;i<n ;i++){
		printf("Enter start and end edge:- ");
		scanf("%d %d",&start,&end);
		printf("if undirecterd a-b b-a press 1:- ");
		scanf("%d",&flag);
		addEdge(g,start,end,flag);
	}
}
void printGraph(graph* g){
	for(int i = 0;i < Max_Size;i++){
		node* curr = g->vertices[i];
		if(curr)
			printf("\n%d -> ",i);
		while(curr){
			printf("%d ",curr->data);
			curr=curr->next;
		}
	}
}
//BFS traversal
void bfsTraversal(graph* g,int data){
	int visited[Max_Size]={0};
	int front = -1;
	int rear = -1;
	int queue[Max_Size];
	visited[data]=1;
	queue[++rear] = data;
	while(front!=rear){
		int temp = queue[++front];
		printf("%d ",temp);
		node* curr = g->vertices[temp];
		while(curr){
			if(!visited[curr->data]){
				visited[curr->data]= 1;
				queue[++rear] = curr->data;
			}
			curr=curr->next;
		}
	}
}
//DFS Traversal
void dfsTraversal(graph* g,int data){
	int top = -1;
	int visited[Max_Size]={0};
	int stack[Max_Size];
	visited[data] = 1;
	stack[++top] = data;
	while(top!=-1){
		int temp = stack[top--];
		printf("%d ",temp);
		
		node* curr = g->vertices[temp];
		while(curr){
			if(!visited[curr->data]){
				visited[curr->data]=1;
				stack[++top] = curr->data;
			}
			curr=curr->next;
		}
	}
}
//0 1 1 0 2 1 1 2 1 1 3 1 2 4 1 3 4 1
int main(){
	graph* g;
	g = createGraph(g);
	takeInput(g);
	printGraph(g);
	int data;
	printf("Enter the point to start traversal:- ");
	scanf("%d",&data);
	printf("\nBFS\n");
	bfsTraversal(g,data);
	printf("\nDFS\n");
	dfsTraversal(g,data);
}
