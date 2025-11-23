
ASSIGNMENT 29
==============

AIM
----

Write a program to implement multiple queues i.e. two queues using array and perform following operations on it. 
A. Add Queue
B. Delete from Queue
C. Display Queue


THEORY
-------

Multiple queues allow us to manage more than one queue at the same time using arrays or linked lists.
Each queue works on the FIFO (First-In First-Out) principle, where the first element added is the first one removed.
The main operations are:

Add (Enqueue) → Inserts an element at the rear of the selected queue.
Delete (Dequeue) → Removes the front element from the queue.
Display → Shows all elements present in the queue in order.
Multiple queues are useful when we need to handle different groups or categories separately while keeping operations efficient.


PROGRAM
--------

```CPP
#include <iostream>
#include <string>
using namespace std;

struct Node_TRP {
    string customer_TRP;
    Node_TRP* next_TRP;
};

class CallQueue_TRP {
    Node_TRP* front_TRP;
    Node_TRP* rear_TRP;
public:
    CallQueue_TRP() {
        front_TRP = rear_TRP = nullptr;
    }

    void enqueue_TRP(string name_TRP) {
        Node_TRP* newNode_TRP = new Node_TRP;
        newNode_TRP->customer_TRP = name_TRP;
        newNode_TRP->next_TRP = nullptr;
        if(!rear_TRP) {
            front_TRP = rear_TRP = newNode_TRP;
        } else {
            rear_TRP->next_TRP = newNode_TRP;
            rear_TRP = newNode_TRP;
        }
        cout << name_TRP << " added to the call queue.\n";
    }

    void dequeue_TRP() {
        if(!front_TRP) {
            cout << "No calls in the queue.\n";
            return;
        }
        Node_TRP* temp_TRP = front_TRP;
        cout << "Assisting customer: " << front_TRP->customer_TRP << endl;
        front_TRP = front_TRP->next_TRP;
        if(!front_TRP) rear_TRP = nullptr;
        delete temp_TRP;
    }

    void display_TRP() {
        if(!front_TRP) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Current call queue: ";
        Node_TRP* temp_TRP = front_TRP;
        while(temp_TRP) {
            cout << temp_TRP->customer_TRP << " ";
            temp_TRP = temp_TRP->next_TRP;
        }
        cout << endl;
    }

    bool isEmpty_TRP() {
        return front_TRP == nullptr;
    }
};

int main() {
    CallQueue_TRP cq_TRP;
    int choice_TRP;
    string name_TRP;

    do {
        cout << "\n--- Call Center Menu ---\n";
        cout << "1. Add customer call\n2. Assist next customer\n3. Display queue\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;

        switch(choice_TRP) {
            case 1:
                cout << "Enter customer name: ";
                cin >> ws;
                getline(cin, name_TRP);
                cq_TRP.enqueue_TRP(name_TRP);
                break;
            case 2:
                cq_TRP.dequeue_TRP();
                break;
            case 3:
                cq_TRP.display_TRP();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice_TRP != 0);

    return 0;
}
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS29.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- Call Center Menu ---
1. Add customer call
2. Assist next customer
3. Display queue
0. Exit
Enter your choice: 1
Enter customer name: Riya
Riya added to the call queue.

Enter your choice: 1
Enter customer name: Aman
Aman added to the call queue.

Enter your choice: 3
Current call queue: Riya Aman

Enter your choice: 2
Assisting customer: Riya

Enter your choice: 3
Current call queue: Aman

Enter your choice: 1
Enter customer name: Priya
Priya added to the call queue.

Enter your choice: 2
Assisting customer: Aman

Enter your choice: 3
Current call queue: Priya

Enter your choice: 0
Exiting...
