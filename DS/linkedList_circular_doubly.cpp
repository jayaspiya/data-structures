#include <iostream>
using namespace std;
// Circular Doubly Linked List
class Node
{
public:
    int data;
    Node *next;
    Node *previous;
    Node()
    {
        data = 0;
        next = NULL;
        previous = NULL;
    }
    Node(int num)
    {
        data = num;
        next = NULL;
        previous = NULL;
    }
};
class LinkedList
{
public:
    Node *last;
    LinkedList()
    {
        last = NULL;
    }
    void addInLast(Node *n);
    void display();
    void addInFront(Node *n);
    bool remove(int num);
    Node *search(int num);
    void addInMiddle(Node *ptr, int num);
};
void printMenu();
int main()
{
    LinkedList l1;
    Node *n1;
    int choice, number;
    bool loop = true;
    while (loop)
    {
        printMenu();
        cout << "Enter Your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // Insert
            while (1)
            {
                cout << "Enter a number (0 to end): ";
                cin >> number;
                if (number == 0)
                {
                    break;
                }
                n1 = new Node(number);
                l1.addInLast(n1);
            }
            break;
        case 2:
            // Display
            l1.display();
            break;
        case 3:
            // Add in front
            cout << "Enter a number: ";
            cin >> number;
            n1 = new Node(number);
            l1.addInFront(n1);
            break;
        case 4:
            // Remove node
            cout << "Enter a number to remove: ";
            cin >> number;
            if (l1.remove(number))
            {
                cout << "Number deleted" << endl;
            }
            else
            {
                cout << "Number not deleted" << endl;
            }
            break;
        case 5:
            // Search
            cout << "Search for: ";
            cin >> number;
            if (l1.search(number) != NULL)
            {
                cout << "Number found" << endl;
            }
            else
            {
                cout << "Number not found" << endl;
            }
            break;
        case 6:
            // Insert in middle
            cout << "After which number: ";
            cin >> number;
            n1 = l1.search(number);
            if (n1 != NULL)
            {
                cout << "Enter the number: ";
                cin >> number;
                l1.addInMiddle(n1, number);
            }
            else
            {
                cout << "Number not found" << endl;
            }
            break;
        case 0:
            // Exit
            loop = false;
            break;
        default:
            cout << "Invalid Entry" << endl;
        }
    }
}
void printMenu()
{
    cout << "******Menu******" << endl;
    cout << "1. Insert node" << endl;
    cout << "2. Display" << endl;
    cout << "3. Insert in the front" << endl;
    cout << "4. Remove" << endl;
    cout << "5. Search" << endl;
    cout << "6. Insert Node in the middle" << endl;
    cout << "0. Exit" << endl;
};
void LinkedList::addInLast(Node *n)
{
    if (last == NULL)
    {
        last = n;
        n->next = n;
        n->previous = n;
    }
    else
    {
        n->next = last->next;
        n->previous = last;
        last->next = n;
        last = n;
        n->next->previous = n;
    }
}
void LinkedList::display()
{
    Node *ptr = last;
    if (last == NULL)
    {
        cout << "Linked List empty" << endl;
    }
    else
    {
        ptr = ptr->next;
        cout << "Head to tail: ";
        while (ptr != last)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << ptr->data << endl;

        cout << "Tail to head: ";
        cout << ptr->data << " ";
        ptr = ptr->previous;
        while (ptr != last)
        {
            cout << ptr->data << " ";
            ptr = ptr->previous;
        }
        cout << endl;
    }
}
void LinkedList::addInFront(Node *n)
{
    if (last == NULL)
    {
        cout << "Linked List empty" << endl;
    }
    else
    {
        n->previous = last;
        n->next = last->next;
        last->next->previous = n;
        last->next = n;
    }
}
bool LinkedList::remove(int num)
{
    if (last->data == num)
    {
        last->previous->next = last->next;
        last->next->previous = last->previous;
        last = last->previous;
        return true;
    }
    else
    {
        Node *ptr = last;
        while (ptr->next != last)
        {
            if (ptr->next->data == num)
            {
                ptr->next->next->previous = ptr;
                ptr->next = ptr->next->next;
                return true;
            }
            ptr = ptr->next;
        }
    }
    return false;
}
Node *LinkedList::search(int num)
{
    if (last->data == num)
    {
        return last;
    }
    else
    {
        Node *ptr = last->next;
        while (ptr != last)
        {
            if (ptr->data == num)
            {
                return ptr;
            }
            ptr = ptr->next;
        }
    }
    return NULL;
}
void LinkedList::addInMiddle(Node *ptr, int num)
{
    Node *n = new Node(num);
    n->previous = ptr;
    n->next = ptr->next;
    ptr->next->previous = n;
    ptr->next = n;
}