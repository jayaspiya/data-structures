#include <iostream>
using namespace std;

class Node{
public:
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
};
class BinaryTree{
public:
	Node *root;
	void insert(int num);
	void insert(int num, Node *leaf);
	void print2D();
	void print2DUtil(Node *leaf, int space);
	
};
void printMenu(){
	cout << "Menu" << endl;
	cout << "1. Add new node" << endl;
	cout << "2. Print Tree" << endl;
	cout << "0. Exit" << endl;
}
int main(){
	BinaryTree *binaryTree = new BinaryTree();
	bool loop = true;
	int choice;
	int number;
	while(loop){
		printMenu();
		cout << "Enter your choice:  ";
		cin >> choice;
		switch(choice){
			case 1:
				while(true){
					cout << "Enter number (0 to exit):  ";
					cin >> number;
					if(number == 0){
						break;
					}
					binaryTree->insert(number);
					}
				break;
			case 2:
				cout << "Printing tree in 2D" << endl;
				binaryTree->print2D();	
				break;
			case 0:
				loop = false;
				break;
			default:
				cout << "Invalid Entry" << endl;
		}
		
	}
	
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

void BinaryTree::print2D(){
	// Pass initial space count as 0
	print2DUtil(root, 0);
}

void BinaryTree::print2DUtil(Node *leaf, int space){
	if(leaf == NULL){
		return;
	}
	space += 5;
	print2DUtil(leaf->right, space);
	cout<<endl;
	for(int i = 5;i < space; i++){
		cout<<" ";
	}
	cout << leaf->data << endl;
	print2DUtil(leaf->left, space);
}
