#include <iostream>
using namespace std;
// Doubly Linked List
// Completed Reverse LinkedList Task
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }
    Node(int num)
    {
        data = num;
        prev = NULL;
        next = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void addInLast(Node *n);
    void display();
    void displayReverse();
    void addInFront(Node *n);
    void addInMiddle(Node *tmp, int num);
    Node *search(int num);
    bool remove(int remove);
    void reverse();
};

void printMenu();

int main()
{
    LinkedList l1;
    Node *n1, *n2;
    int choice, number, preNum;
    while (1)
    {
        printMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            // Adding Node to last
            while (1)
            {
                cout << "Insert a number(0 to end): ";
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
            // Display linked list from head to tail
            l1.display();
            break;
        case 3:
            // Display linked list from tail to head
            l1.displayReverse();
            break;
        case 4:
            // Insert in front
            cout << "Insert a number : ";
            cin >> number;
            n1 = new Node(number);
            l1.addInFront(n1);

            break;
        case 5:
            // Search node
            cout << "Enter the node you want to search : ";
            cin >> number;
            if (l1.search(number) != NULL)
            {
                cout << "Number found";
            }
            else
            {
                cout << "404 Number not found";
            }
            cout << endl;
            break;

        case 6:
            // Insert in the middle
            cout << "After which num you want to insert" << endl;
            cin >> preNum;
            n2 = l1.search(preNum);
            if (n2 == NULL)
            {
                cout << "404 not found" << endl;
            }
            else
            {
                cout << "Enter number to insert" << endl;
                cin >> number;
                l1.addInMiddle(n2, number);
            }
            break;
        case 7:
            // Remove Node
            cout << "Delete: ";
            cin >> number;
            if (l1.remove(number))
            {
                cout << number << " deleted" << endl;
            }
            else
            {
                cout << "No number deleted" << endl;
            }
            break;
        case 8:
            //reverse
            l1.reverse();
            break;
        case 0:
            // EXIT
            return 1;
        default:
            cout << "Enter a valid choice" << endl;
        }
    }
    return 0;
}
void printMenu()
{
    cout << "1. Insert item." << endl;
    cout << "2. Display." << endl;
    cout << "3. Reverse Display" << endl;
    cout << "4. Insert item in front" << endl;
    cout << "5. Search node" << endl;
    cout << "6. Insert Node in the middle" << endl;
    cout << "7. Delete Node." << endl;
    cout << "8. Reverse LL" << endl;
    cout << "0. Exit." << endl;
}
void LinkedList::addInLast(Node *n)
{
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
};

void LinkedList::display()
{
    Node *ptr = this->head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void LinkedList::displayReverse()
{
    Node *ptr = this->tail;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }
    cout << endl;
}

void LinkedList::addInFront(Node *n)
{
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        n->next = head;
        head->prev = n;
        head = n;
    }
}

Node *LinkedList::search(int num)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == num)
            {
                return ptr;
            }
            ptr = ptr->next;
        }
    };
    return NULL;
}
void LinkedList::addInMiddle(Node *tmp, int num)
{
    Node *n1;
    n1 = new Node(num);
    n1->next = tmp->next;
    n1->prev = tmp;
    tmp->next->prev = n1;
    tmp->next = n1;
}
bool LinkedList::remove(int number)
{
    // Check whether the linked list is empty
    Node *tmp = head;
    Node *data;
    // If linked list is empty
    if (tmp == NULL)
    {
        return false;
    }
    data = this->search(number);
    // Check if the number exist or not
    if (data == NULL)
    {
        return false;
    }
    // Check if it is the only item in the list
    if (data->prev == NULL && data->next == NULL)
    {
        head = NULL;
        tail = NULL;
        return true;
    }
    // Deleting first node.
    if (data->prev == NULL)
    {
        data->next->prev = NULL;
        head = data->next;
        data->next = NULL;
        return true;
    }
    // Deleting last node
    if (data->next == NULL)
    {
        data->prev->next = NULL;
        tail = data->prev;
        data->prev = NULL;
        return true;
    }
    // Deleting middle node
    data->prev->next = data->next;
    data->next->prev = data->prev;
    data->next = NULL;
    data->prev = NULL;
    return true;
}
void LinkedList::reverse()
{
    Node *ptr = head;
    Node *tmp;
    if (ptr == NULL)
    {
        cout << "The linked list is empty" << endl;
        return;
    }
    while (ptr != NULL)
    {
        tmp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = tmp;
        ptr = ptr->prev;
    }
    tmp = head;
    head = tail;
    tail = tmp;
    cout << "Linked List Reversed" << endl;
}