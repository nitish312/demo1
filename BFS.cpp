#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left, *right;

	Node(int data){
		this->data = data;
		left = right = NULL;
	}
};

bool printLevel(Node *root, int level){

	if(!root) return false;

	if(level == 1){
		cout<<root->data<<" ";
		return true; 
	}

	bool left = printLevel(root->left, level-1);
	bool right = printLevel(root->right, level-1);

	return left || right;
}

void levelOrder(Node *root){

	int level = 1;
	while(printLevel(root, level)){
		level++;
	}	
}

int main(){

	Node * root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	root->right->left = new Node(6);
	root->right->right = new Node(7);

	cout<<"Breadth First Search : "<<endl;

	levelOrder(root);

	return 0;
}