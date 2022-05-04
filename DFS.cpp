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

void preOrder(Node *root){

	if(!root) return;

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root){

	if(!root) return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void postOrder(Node *root){

	if(!root) return;

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

int main(){

	Node * root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	root->right->left = new Node(6);
	root->right->right = new Node(7);

	cout<<"Depth First Search : "<<endl;

	cout<<endl<<"Pre-Order Traversal  - ";
	preOrder(root);

	cout<<endl<<"In-Order  Traversal  - ";
	inOrder(root);

	cout<<endl<<"Post-Order Traversal - ";
	postOrder(root);

	return 0;
}