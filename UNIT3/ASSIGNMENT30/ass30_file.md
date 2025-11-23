
ASSIGNMENT 30
==============

AIM
----
In a call center, customer calls are handled on a first-come, first-served basis. Implement a queue system using Linked list where:
    ●	Each customer call is enqueued as it arrives.
    ●	Customer service agents dequeue calls to assist customers.
    ●	If there are no calls, the system waits.


THEORY
------

A queue is a linear data structure that works on the FIFO (First-In First-Out) principle, where the first element added is the first one removed.
In a call center, customer calls must be handled in the same order they arrive. Using a linked list, we can dynamically store calls without any fixed size limit.

Enqueue adds a new customer call at the rear of the queue.
Dequeue removes the call at the front when an agent is ready.
If the queue is empty, no calls are available for assistance.
This system ensures smooth and fair handling of calls in real-time.


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

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS30.cpp

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
Enter customer name: Neha
Neha added to the call queue.

Enter your choice: 2
Assisting customer: Aman

Enter your choice: 3
Current call queue: Neha

Enter your choice: 0
Exiting...
