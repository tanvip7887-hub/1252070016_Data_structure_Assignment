
ASSIGNMENT 20
===============

AIM 
----

Given a list, split it into two sublists — one for the front half, and one for the back half. If the number of elements is odd, the extra 
element should go in the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}. 
Getting this right for all the cases is harder than it looks. You should check your solution against a few cases (length = 2, length = 3, length=4)
to make sure that the list gets split correctly near the shortlist boundary conditions. If it works right for length=4, it probably works right for length=1000. You will probably need special case code to deal with the (length <2) cases.


THEORY
-------

Front–Back Split is an operation on a singly linked list where the list is divided into two separate sublists.
If the list has an odd number of nodes, the extra node always goes to the front list.
The split is usually done using the slow and fast pointer approach, where the fast pointer moves two steps and the slow pointer moves one step.
When the fast pointer reaches the end, the slow pointer reaches the midpoint.
This method works efficiently and handles edge cases like empty list or single-node list.
It helps in algorithms like Merge Sort and in operations where the list needs to be processed in two halves.


PROGRAM
---------

```CPP
#include <iostream>
using namespace std;

struct Node_TRP {
    int data_TRP;
    Node_TRP* next_TRP;
};

Node_TRP* createNode_TRP(int data_TRP) {
    Node_TRP* newNode_TRP = new Node_TRP;
    newNode_TRP->data_TRP = data_TRP;
    newNode_TRP->next_TRP = nullptr;
    return newNode_TRP;
}

void append_TRP(Node_TRP*& head_TRP, int data_TRP) {
    Node_TRP* newNode_TRP = createNode_TRP(data_TRP);
    if (!head_TRP) {
        head_TRP = newNode_TRP;
        return;
    }
    Node_TRP* temp_TRP = head_TRP;
    while (temp_TRP->next_TRP) temp_TRP = temp_TRP->next_TRP;
    temp_TRP->next_TRP = newNode_TRP;
}

void printList_TRP(Node_TRP* head_TRP) {
    while (head_TRP) {
        cout << head_TRP->data_TRP << " ";
        head_TRP = head_TRP->next_TRP;
    }
    cout << endl;
}

void frontBackSplit_TRP(Node_TRP* source_TRP, Node_TRP*& front_TRP, Node_TRP*& back_TRP) {
    if (!source_TRP || !source_TRP->next_TRP) {
        front_TRP = source_TRP;
        back_TRP = nullptr;
        return;
    }
    Node_TRP* slow_TRP = source_TRP;
    Node_TRP* fast_TRP = source_TRP->next_TRP;
    while (fast_TRP) {
        fast_TRP = fast_TRP->next_TRP;
        if (fast_TRP) {
            slow_TRP = slow_TRP->next_TRP;
            fast_TRP = fast_TRP->next_TRP;
        }
    }
    front_TRP = source_TRP;
    back_TRP = slow_TRP->next_TRP;
    slow_TRP->next_TRP = nullptr;
}

int main() {
    Node_TRP* head_TRP = nullptr;
    Node_TRP* front_TRP = nullptr;
    Node_TRP* back_TRP = nullptr;
    int choice_TRP, value_TRP;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert element\n";
        cout << "2. Display list\n";
        cout << "3. Split list into front and back\n";
        cout << "4. Display front and back lists\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;

        switch(choice_TRP) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value_TRP;
                append_TRP(head_TRP, value_TRP);
                break;
            case 2:
                cout << "Original list: ";
                printList_TRP(head_TRP);
                break;
            case 3:
                frontBackSplit_TRP(head_TRP, front_TRP, back_TRP);
                cout << "List has been split.\n";
                break;
            case 4:
                cout << "Front list: ";
                printList_TRP(front_TRP);
                cout << "Back list: ";
                printList_TRP(back_TRP);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice_TRP != 0);

    return 0;
}
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS20.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- Menu ---
1. Insert element
2. Display list
3. Split list into front and back
4. Display front and back lists
0. Exit
Enter your choice: 1
Enter value to insert: 2

Enter your choice: 1
Enter value to insert: 3

Enter your choice: 1
Enter value to insert: 5

Enter your choice: 1
Enter value to insert: 7

Enter your choice: 1
Enter value to insert: 11

Enter your choice: 2
Original list: 2 3 5 7 11

Enter your choice: 3
List has been split.

Enter your choice: 4
Front list: 2 3 5
Back list: 7 11

Enter your choice: 0
Exiting...
