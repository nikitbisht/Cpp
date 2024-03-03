#include<iostream>
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

void dfs(Graph* g,int value,int* visited){
	visited[value] = true;
	cout<<value<<" ";
	node* neigh = g->vertices[value];
	while(neigh){
		if(!visited[neigh->data]){
			dfs(g,neigh->data,visited);
		}
		neigh = neigh->next;
	}
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
	cout<<"Dfs Traversal:- ";
	int visited[Max_Size] = {0};
	dfs(g,u,visited);
	return 0;
}