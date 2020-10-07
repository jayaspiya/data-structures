#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int num)
    {
        data = num;
        next = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    void addInLast(Node *n);
    void addInFront(Node *n);
    void remove(int number);
    Node *search(int n);
    void display();

    LinkedList()
    {
        head = NULL;
    }
};

void LinkedList::addInLast(Node *n)
{
    if (head == NULL)
    {
        this->head = n;
    }
    else
    {
        Node *tmp = this->head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = n;
    }
}

void LinkedList::addInFront(Node *n)
{
    n->next = head;
    head = n;
}
Node *LinkedList::search(int value)
{
    //cout << value <<endl;
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            if (ptr->data == value)
            {
                return ptr;
            }
            ptr = ptr->next;
        }
    }
    return NULL;
}
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
void LinkedList::remove(int number)
{
    Node *tmp, *prev = NULL;
    tmp = this->head;
    //check if the number is the first item
    if (tmp->data == number)
    {
        this->head = tmp->next;
        cout << "Number deleted from the first node" << endl;
    }
    // now we need to traverse
    while (tmp->next != NULL)
    {
        if (tmp->data == number)
        {
            prev->next = tmp->next;
            cout << "Deleted" << endl;
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
int main()
{
    LinkedList l1;
    Node *n1, *n2;
    int choice;
    int number;
    while (1)
    {
        cout << "1. Insert item." << endl;
        cout << "2. Display." << endl;
        cout << "3. Insert Item in front." << endl;
        cout << "4. Search Node" << endl;
        cout << "5. Enter node in middle" << endl;
        cout << "6. Delete the node" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Your Choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            while (1)
            {
                cout << "Insert a number(0 to end):" << endl;
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
            l1.display();
            break;
        case 3:
            cout << "Insert a number to insert at front" << endl;
            cin >> number;
            n1 = new Node(number);
            l1.addInFront(n1);
            break;
        case 4:
            cout << "Insert searching Node" << endl;
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
        case 5:
            cout << "After which number:" << endl;
            cin >> number;
            n2 = l1.search(number);
            if (n2 == NULL)
            {
                cout << "Can't find the given number" << endl;
                break;
            }
            cout << "Insert number in the middle" << endl;
            cin >> number;
            n1 = new Node(number);
            n1->next = n2->next;
            n2->next = n1;
            break;
        case 6:
            cout << "Which number do you want to delete?" << endl;
            cin >> number;
            n2 = l1.search(number);
            if (n2 == NULL)
            {
                cout << "Cant find the given number" << endl;
                break;
            }
            l1.remove(number);
            break;
        case 0:
            return 1;
        default:
            cout << "Enter a valid choice" << endl;
        }
    }
    return 0;
}