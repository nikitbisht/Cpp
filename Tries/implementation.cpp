#include<iostream>
using namespace std;
class TrieNode{
	public:
		char data;
		TrieNode* children[26];
		bool isTreminal;
		
	TrieNode(char data){
		this->data = data;
		for(int i=0;i<26;i++){
			children[i]=NULL;
		}
		isTreminal = false;
	}
};
class Trie{
	public:
		TrieNode* root ;
	Trie(){
		root = new TrieNode('\0');
	}
	private:
//insert
	void insertUtil(TrieNode* root,string word){
		//base case
		if(word.size() == 0){
			root->isTreminal = true;
			return ;
		}
		char ch = word[0];
		int index = ch -'a';
		TrieNode* child ;
		
		//present
		if(root->children[index] != NULL){
			child = root->children[index];	
		}else{
			child = new TrieNode(ch);
			root->children[index] = child;
		}
		
		//recursive call
		insertUtil(child,word.substr(1));
	}
	
//Search function
	bool searchUtil(TrieNode* root,string word){
		//base case
		if(word.size() == 0){
			return root->isTreminal;
		}
		int index = word[0]-'a';
		TrieNode* child;
		//present
		if(root->children[index]!=NULL){
			child = root->children[index];
		}else{
			return false;
		}
		//recursive call
		return searchUtil(child,word.substr(1));
	}

//remove word
	void removeUtil(TrieNode* root,string word){
		//base case
		if(word.size() == 0){
			root->isTreminal = false;
			return ;
		}
		int index = word[0]-'a';
		TrieNode* child;
		//present
		if(root->children[index]!=NULL){
			child = root->children[index];
		}else{
			return ;
		}
		//recursive call
		removeUtil(child,word.substr(1));
	}
	public:
	void insertWord(string word){
		insertUtil(root,word);
	}
	bool searchWord(string word){
		return searchUtil(root,word);
	}
	void removeWord(string word){
		removeUtil(root,word);
	}
};
int main(){
	Trie* t = new Trie();
	t->insertWord("hello");
	t->insertWord("Nikit");
	if(t->searchWord("Nikit")){
		cout<<"word find"<<endl;
	}else{
		cout<<"not found"<<endl;
	}
}
