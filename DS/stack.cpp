#include <iostream>
using namespace std;
class Stack
{
    int *base;
    int top;
    int total_capacity;

public:
    Stack(int size);
    void push(int x);
    int pop();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};
void printMenu();
int main()
{
    int num, ch;
    cout << "Enter the size of stack: ";
    cin >> num;
    Stack stk(num);
    cout << "Stack size is: " << stk.size() << endl;
    bool loop = true;
    while(loop){
    	printMenu();
    	cout << "Enter your choice" << endl;
    	cin >> ch;
    	switch(ch){
    		case 1:
    			// Push
    			cout << "Enter the element to push: ";
    			cin >> num;
    			stk.push(num);
    			cout << "Stack size is: " << stk.size() << endl;
    			break;
    		case 2:
    			// Pop
    			break;
    		case 3:
    			// Peek
    			break;
    		case 4:
    			// Get Size of the stack
    			cout << "Stack size: " << stk.size() << endl;
    			break;
    		case 0:
    			loop = false;
    			break;
    		default:
    			cout << "Invalid Entry" << endl;
    	}
    }
}
void printMenu(){
	cout << endl <<"Menu" << endl;
	cout << "1. Push an element to stack" << endl;
	cout << "2. Pop an element from stack"<< endl;
	cout << "3. Peek an element on stack" << endl;
	cout << "4. Find size of stack" << endl;
	cout << "0. Exit" << endl;
}
Stack::Stack(int size)
{
    base = new int[size];
    total_capacity = size;
    // at first top is pointing nothing
    top = -1;
}

void Stack::push(int n){
	// Check whether the stack is full
	if(isFull()){
		cout << "Cannot push new element. Stack full" << endl;
		return;
	}
	top++;
	*(base + top) = n;
	cout << "New element has been pushed successfully" << endl;
	
}

bool Stack::isFull(){
	if(size() == total_capacity){
		return true;
	}
	return false;
}
int Stack::size(){
	return top + 1;
}