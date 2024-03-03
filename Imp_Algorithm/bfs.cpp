//dfs
#include<iostream>
#include<bits/stdc++.h>
#define Max_Size 10
using namespace std;
class node{
	public:
		int data;
		node* next;
	//Constructor
	node(int data){
		this->data = data;
		next = NULL;
	}
};
class Graph{
	public:
		node* vertices[Max_Size];
		
	Graph(){
		for(int i=0; i<Max_Size; i++){
			vertices[i] = NULL;
		}
	}
	
	void Edge(int u,int v){
		node* newnode = new node(v);
		newnode->next = vertices[u];
		vertices[u] =newnode;
		newnode = new node(u);
		newnode->next = vertices[v];
		vertices[v] = newnode;
	}
	
	void print(){
		node* current = NULL;
		for(int i=0; i<Max_Size; i++){
			if(vertices[i]){
				current = vertices[i];
				cout<<i<<" Vertex:- ";
				while(current){
					cout<<current->data<<" ";
					current = current->next;
				}
				cout<<endl;
			}
		}
	}
};
class queue1{
	public:
		node* front;
		node* rear;
	//constructor
	queue1(){
		rear = front = NULL;
	}
	void push(int data){
		node* newnode = new node(data);
		if(rear == NULL){
			rear = front = newnode;
		}else{
			rear->next = newnode;
			rear = newnode;
		}
	}
	int top(){
		return front->data;
	}
	bool empty(){
		return front == NULL;
	}
	void pop(){
		if(front == NULL){
			return ;
		}
		node* temp = front;
		front = front->next;
		delete temp;
		if(empty()){
			front = rear = NULL;
		}
	}
};


void bfs(Graph* g,int u){
	int visited[Max_Size] = {0};
	visited[u] = true;
	queue1 *q = new queue1();
	q->push(u);
	while(!q->empty()){
		int front = q->top();
		q->pop();
		cout<<front<<" ";
		node* neigh = g->vertices[front];
		while(neigh){
			if(!visited[neigh->data]){
				visited[neigh->data] = true;
				q->push(neigh->data);
			}
			neigh = neigh->next;
		}
	}
	delete q;
}
int main(){
	Graph* g = new Graph();
	int n,u,v;
	cout<<"Enter the no of Vertices:- "<<endl;
	cin>>n;
	
	for(int i=0; i<n; i++){
		cout<<"Start Vertex:- ";
		cin>>u;
		cout<<"End Vertex:- ";
		cin>>v;
		g->Edge(u,v);
		cout<<endl;
	}
	cout<<"Graph Representation"<<endl;
	g->print();
	cout<<endl;
	cout<<"Bfs Traversal:- ";
	bfs(g,u);
	return 0;
}