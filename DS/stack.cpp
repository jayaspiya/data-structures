#include <iostream>
using namespace std;
class Stack
{
    int *base;
    int top;
    int total_capacity;

public:
    Stack(int size);
};

int main()
{
    int num;
    cout << "Enter the size of stack: ";
    cin >> num;
    // Stack stk = new Stack(num);
}

Stack::Stack(int size)
{
    base = new int[size];
    total_capacity = size;
    // at first top is pointing nothing
    top = -1;
}