#include <iostream>
using namespace std;

class Node{
	int data;
	Node *right;
	Node *left;
	Node(){
		data = 0;
		left = NULL;
		right = NULL;
	}
	Node(int number){
		data = number;
		left = NULL;
		right = NULL;
	}
}
class BinaryTree{
public:
	Node *root;
	void insert(int num);
	void insert(int num, Node *leaf);
	
}
void printMenu(){
	cout << "Menu" << endl;
	cout << "Add new node" << endl;
}
int main(){
    
}
void BinaryTree::insert(int num){
	if(root == NULL){
		root = new Node(num);
		
	}else{
		insert(num, root);
	}
}
void BinaryTree::insert(int num, Node *leaf){
	if(num < leaf->data){
		if(leaf->left != NULL){
			insert(num, leaf->left);
		}
		else{
			leaf->left = new Node(num);
		}	
	}
	else{
		if(leaf->right != NULL){
			insert(num, leaf->right);
		}
		else{
			leaf->right = new Node(num);
		}	
	}
}


