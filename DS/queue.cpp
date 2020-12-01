#include<iostream>
using namespace std;

class Queue
{
	int *base;
	int front;
	int rear;
	int total_capacity;
public:
	Queue(int size);
	void enqueue(int x);
	int dequeue();
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
};
void printMenu();
int main(){
	int num, ch;
	bool loop = true;
	cout << "Enter the maximum capacity of the queue: " ;
	cin >> num;
	Queue queue(num);
	while(loop){
		printMenu();
		cout << "Enter your choice: " ;
		cin >> ch;
		switch(ch){
			case 1:
				cout << "Enter the element to enqueue: ";
				cin >> num;
				queue.enqueue(num);
				cout << "Queue size: " << queue.size() << endl;
				break;
			case 2:
				num = queue.dequeue();
				cout << num << " dequeued" << endl;
				cout << "Queue size: " << queue.size() << endl;
				break;
			case 3:
				num = queue.peek();
				cout << num << " peeked" << endl;
				break;
			case 4:
				num = queue.size();
				cout << "The size of queue: " << num << endl; 
			case 0:
				loop = false;
				break;
			default:
				cout << "Invalid selection" << endl;
		}
	}
}
void printMenu(){
	cout << endl;
	cout << "Menu" << endl;
	cout << "1. Enqueue an element" << endl;
	cout << "2. Dequece an element" << endl;
	cout << "3. Peek an element" << endl;
	cout << "4. Size of the queue" << endl;
	cout << "0. Exit" << endl;
	cout << endl;
}
Queue::Queue(int size){
	base = new int[size];
	total_capacity = size;
	front = 0;
	rear = -1;
};

void Queue::enqueue(int num){
	// Check if the queue is full
	if(isFull()){
		cout << "Cannot enqueue. Queue full" << endl;
		return;
	}
	rear++;
	*(base + rear) = num;
	
}
int Queue::dequeue(){
	if(isEmpty()){
		cout << "Cannot dequeue. Queue Empty" << endl;
		return 0;
	}
	int dequeue_num = *(base + front);
	front++;
	return dequeue_num;
}
int Queue::peek(){
	if (isEmpty()){
		cout << "Cannot peek. Queue Empty" << endl;
		return 0;
	}
	int peeked_number = *(base + front);
	return peeked_number;
}
bool Queue::isFull(){
	if (size() >= total_capacity){
		return true;
	}
	return false;
}
bool Queue::isEmpty(){
	if(front >= rear){
		return true;
	}
	return false;
}
int Queue::size(){
	return (rear - front + 1);
}