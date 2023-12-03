/*
Q12. Write a C program to implement BFS.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max_Size 10
typedef struct node{
  	int data;
  	struct node* next;
}node;

typedef struct Graph{
	node* vertices[Max_Size];
}Graph;

typedef struct queue{
	node* front;
	node* rear;
}Queue;
bool queueIsEmpty(Queue* queue){
	return queue->front==NULL;
}

int dequeue(Queue* queue){
	if(queue->front==NULL){
		printf("Queue is empty");
	}
	node* temp=queue->front;
	int data=temp->data;
	queue->front=queue->front->next;
	free(temp);
	if(queueIsEmpty(queue)){
		queue->front=queue->rear=NULL;
	}
	return data;
}

Graph* createGraph(){
	Graph* graph=(Graph*)malloc(sizeof(Graph));
	for(int i=0;i<Max_Size;i++){
		graph->vertices[i]=NULL;
	}
	return graph;
}
void addEdege(Graph* graph,int start,int end){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = end;
	newnode->next=graph->vertices[start];
	graph->vertices[start]=newnode;
	//undirected graph
	newnode = (node*)malloc(sizeof(node));
	newnode->data=start;
	newnode->next=graph->vertices[end];
	graph->vertices[end]=newnode;
}
void takeEdge(Graph* graph){
	int n,start,end;
	printf("\nEnter the no of Edege:- ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("\nStart vertex:- ");
		scanf("%d",&start);
		printf("End vertex:- ");
		scanf("%d",&end);
		addEdege(graph,start,end);
	}
}

void enqueue(Queue* queue,int data){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	if(queue->rear==NULL){
		queue->front=queue->rear=newnode;
	}else{
		queue->rear->next=newnode;
		queue->rear=newnode;		
	}
}

void bfsTraversal(Graph* graph){
	int data;
	for(int i=0;i<Max_Size;i++){
		if(graph->vertices[i]){
			data=graph->vertices[i]->data;
			break;
		}
	}
	printf("BFS Traversal:- ");
	int visited[Max_Size]={0};
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front=NULL;
	queue->rear=NULL;
	enqueue(queue,data);
	visited[data]=1;
	while(!queueIsEmpty(queue)){
		int front=dequeue(queue);
		printf(" %d",front);
		
		node* current=graph->vertices[front];
		while(current){
			if(!visited[current->data]){
				visited[current->data]=1;
				enqueue(queue,current->data);
			}
			current=current->next;
		}
	}
	printf("\n");
	free(queue);
}

void displayGraph(Graph* graph){
	node* current=NULL;
	for(int i=0;i<Max_Size;i++){
		if(graph->vertices[i]){
			current=graph->vertices[i];
			printf("\n%d vertex:- ",i);
			while(current){
				printf(" %d",current->data);
				current=current->next;
			}
		}
	}
	printf("\n");  
}
int main(){
	Graph* graph = createGraph();
	int n;
	up:
	printf("\nEnter the Operation:- ");
	printf("\n1. Add edges.");
	printf("\n2. BFS Travesal.");
	printf("\n3. Display Graph.");
	printf("\n4. Exit.");	
	printf("\n");
	scanf("%d",&n);
	switch(n){
		case 1:
			takeEdge(graph);
			break;
		case 2:
			bfsTraversal(graph);
			break;
		case 3:
			displayGraph(graph);
			break;
		case 4:
			exit(0);
			break;
		default:	
			printf("\nInvalid Input");
	}
	goto up;
	return 0;
}
/*

Enter the Operation:-
1. Add edges.
2. BFS Travesal.
3. Display Graph.
4. Exit.
1

Enter the no of Edege:- 6

Start vertex:- 0
End vertex:- 1

Start vertex:- 0
End vertex:- 2

Start vertex:- 1
End vertex:- 2

Start vertex:- 1
End vertex:- 3

Start vertex:- 2
End vertex:- 4

Start vertex:- 3
End vertex:- 4

Enter the Operation:-
1. Add edges.
2. BFS Travesal.
3. Display Graph.
4. Exit.
3

0 vertex:-  2 1
1 vertex:-  3 2 0
2 vertex:-  4 1 0
3 vertex:-  4 1
4 vertex:-  3 2

Enter the Operation:-
1. Add edges.
2. BFS Travesal.
3. Display Graph.
4. Exit.
2
BFS Traversal:-  2 4 1 0 3

*/