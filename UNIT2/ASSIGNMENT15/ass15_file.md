 
ASSIGNMENT 15
===============

AIM
----

 Write a C++ program to store a binary number using a doubly linked list. 
 Implement the following functions:
 a) Calculate and display the 1’s complement and 2’s complement of the stored binary number.
 b) Perform addition of two binary numbers represented using doubly linked lists and display the result.


THEORY
-------

The ticket reservation system uses a doubly circular linked list to store and manage seat information for each row in a multiplex. Each seat is represented as a node, and the circular connection allows smooth movement forward and backward through seats. An array of head pointers stores 
the starting node of every row. This structure helps to quickly display available seats, book a seat, and cancel a booking. It also makes the system efficient because no shifting of data is needed—only node links are updated.

PROGRAM
--------

```CPP
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* insert(Node* head, int bit) 
{
    Node* n = new Node();
    n->data = bit;
    n->next = NULL;

    if (!head) 
    {
        n->prev = NULL;
        return n;
    }

    Node* t = head;
    while (t->next)
        t = t->next;

    t->next = n;
    n->prev = t;
    return head;
}

void display(Node* head) 
{
    Node* t = head;
    while (t) 
    {
        cout << t->data;
        t = t->next;
    }
    cout << endl;
}

void onesComplement(Node* head) 
{
    Node* t = head;
    while (t) 
    {
        t->data = (t->data == 0) ? 1 : 0;
        t = t->next;
    }
}

Node* twosComplement(Node* head) 
{
    onesComplement(head);  

    Node* t = head;
    while (t->next)
        t = t->next;  

    int carry = 1;

    while (t && carry) 
    {
        if (t->data == 1 && carry == 1) 
        {
            t->data = 0;
            carry = 1;
        } 
        else if (t->data == 0 && carry == 1) 
        {
            t->data = 1;
            carry = 0;
        }
        t = t->prev;
    }

    if (carry == 1) 
    {
        Node* n = new Node();
        n->data = 1;
        n->prev = NULL;
        n->next = head;
        head->prev = n;
        head = n;
    }
    return head;
}

Node* insertFront(Node* head, int bit) 
{
    Node* n = new Node();
    n->data = bit;
    n->prev = NULL;
    n->next = head;

    if (head)
        head->prev = n;
    return n;
}

Node* add(Node* h1, Node* h2) 
{
    Node* t1 = h1;
    Node* t2 = h2;

    while (t1 && t1->next)
        t1 = t1->next;
    
    while (t2 && t2->next)
        t2 = t2->next;

    Node* result = NULL;
    int carry = 0;

    while (t1 || t2 || carry) 
    {
        int sum = carry;
        if (t1) 
        {
            sum += t1->data;
            t1 = t1->prev;
        }
        if (t2) 
        {
            sum += t2->data;
            t2 = t2->prev;
        }

        result = insertFront(result, sum % 2);
        carry = sum / 2;
    }
    return result;
}

int main() 
{
    int choice;

    do
    {
        cout << "\n1. Find 1's and 2's Complement";
        cout << "\n2. Add Two Binary Numbers";
        cout << "\n3. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: 
            {
                Node* head = NULL;
                string bin;

                cout << "Enter binary number: ";
                cin >> bin;

                for (char ch : bin)
                    head = insert(head, ch - '0');

                cout << "Original Binary: ";
                display(head);

                Node* one = NULL;
                Node* t = head;
                while (t) 
                {
                    one = insert(one, t->data);
                    t = t->next;
                }
                onesComplement(one);
                cout << "1's Complement: ";
                display(one);

                Node* two = NULL;
                t = head;
                while (t) 
                {
                    two = insert(two, t->data);
                    t = t->next;
                }
                two = twosComplement(two);
                cout << "2's Complement: ";
                display(two);

                break;
            }

            case 2: 
            {
                Node* h1 = NULL;
                Node* h2 = NULL;
                string bin1, bin2;

                cout << "Enter first binary number: ";
                cin >> bin1;
                cout << "Enter second binary number: ";
                cin >> bin2;

                for (char ch : bin1)
                    h1 = insert(h1, ch - '0');
                for (char ch : bin2)
                    h2 = insert(h2, ch - '0');

                cout << "First Binary: ";
                display(h1);
                cout << "Second Binary: ";
                display(h2);

                Node* result = add(h1, h2);
                cout << "Addition Result: ";
                display(result);

                break;
            }

            case 3: 
                cout << "\nExiting program...\n";
                break;

            default: 
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while(choice != 3);

    return 0;
}
```


OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS15.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

1. Find 1's and 2's Complement
2. Add Two Binary Numbers
3. Exit

Enter your choice: 1

Enter binary number: 1011
Original Binary: 1011
1's Complement: 0100
2's Complement: 0101

1. Find 1's and 2's Complement
2. Add Two Binary Numbers
3. Exit

Enter your choice: 2

Enter first binary number: 1000
Enter second binary number: 1111
First Binary: 1000
Second Binary: 1111
Addition Result: 10111

1. Find 1's and 2's Complement
2. Add Two Binary Numbers
3. Exit

Enter your choice: 3

Exiting program...