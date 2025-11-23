
ASSIGNMENT 19
==============

AIM - WAP to create a doubly linked list and perform following operations on it.A) Insert (all cases) 2. Delete (all cases).


THEORY
-------

A doubly linked list is a linear data structure where each node contains data and two pointers: one to the next node and one to the previous node.
It allows easy movement in both forward and backward directions.
Insertion can be done at the beginning, end, or after a specific node by adjusting the next and previous pointers.
Deletion is also simple because each node knows its previous and next node, so removing a node does not break the chain.
This structure is useful for applications like navigation systems, undo–redo operations, and playlist management.


PROGRAM
--------

```CPP
#include <iostream>
using namespace std;

struct Node_TRP {
    int data_TRP;
    Node_TRP* prev_TRP;
    Node_TRP* next_TRP;
};

Node_TRP* head_TRP = nullptr;

Node_TRP* createNode_TRP(int data_TRP) {
    Node_TRP* newNode_TRP = new Node_TRP;
    newNode_TRP->data_TRP = data_TRP;
    newNode_TRP->prev_TRP = nullptr;
    newNode_TRP->next_TRP = nullptr;
    return newNode_TRP;
}

void display_TRP() {
    Node_TRP* temp_TRP = head_TRP;
    cout << "List: ";
    while (temp_TRP != nullptr) {
        cout << temp_TRP->data_TRP << " ";
        temp_TRP = temp_TRP->next_TRP;
    }
    cout << endl;
}

void insertAtBeginning_TRP(int data_TRP) {
    Node_TRP* newNode_TRP = createNode_TRP(data_TRP);
    if (head_TRP == nullptr) {
        head_TRP = newNode_TRP;
        return;
    }
    newNode_TRP->next_TRP = head_TRP;
    head_TRP->prev_TRP = newNode_TRP;
    head_TRP = newNode_TRP;
}

void insertAtEnd_TRP(int data_TRP) {
    Node_TRP* newNode_TRP = createNode_TRP(data_TRP);
    if (head_TRP == nullptr) {
        head_TRP = newNode_TRP;
        return;
    }
    Node_TRP* temp_TRP = head_TRP;
    while (temp_TRP->next_TRP != nullptr) {
        temp_TRP = temp_TRP->next_TRP;
    }
    temp_TRP->next_TRP = newNode_TRP;
    newNode_TRP->prev_TRP = temp_TRP;
}

void insertAfter_TRP(int value_TRP, int data_TRP) {
    Node_TRP* temp_TRP = head_TRP;
    while (temp_TRP != nullptr && temp_TRP->data_TRP != value_TRP) {
        temp_TRP = temp_TRP->next_TRP;
    }
    if (temp_TRP == nullptr) {
        cout << "Value not found!\n";
        return;
    }
    Node_TRP* newNode_TRP = createNode_TRP(data_TRP);
    newNode_TRP->next_TRP = temp_TRP->next_TRP;
    newNode_TRP->prev_TRP = temp_TRP;
    if (temp_TRP->next_TRP != nullptr)
        temp_TRP->next_TRP->prev_TRP = newNode_TRP;
    temp_TRP->next_TRP = newNode_TRP;
}

void deleteFromBeginning_TRP() {
    if (head_TRP == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    Node_TRP* temp_TRP = head_TRP;
    head_TRP = head_TRP->next_TRP;
    if (head_TRP != nullptr)
        head_TRP->prev_TRP = nullptr;
    delete temp_TRP;
}

void deleteFromEnd_TRP() {
    if (head_TRP == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    Node_TRP* temp_TRP = head_TRP;
    while (temp_TRP->next_TRP != nullptr) {
        temp_TRP = temp_TRP->next_TRP;
    }
    if (temp_TRP->prev_TRP != nullptr)
        temp_TRP->prev_TRP->next_TRP = nullptr;
    else
        head_TRP = nullptr;
    delete temp_TRP;
}

void deleteValue_TRP(int value_TRP) {
    Node_TRP* temp_TRP = head_TRP;
    while (temp_TRP != nullptr && temp_TRP->data_TRP != value_TRP) {
        temp_TRP = temp_TRP->next_TRP;
    }
    if (temp_TRP == nullptr) {
        cout << "Value not found!\n";
        return;
    }
    if (temp_TRP->prev_TRP != nullptr)
        temp_TRP->prev_TRP->next_TRP = temp_TRP->next_TRP;
    else
        head_TRP = temp_TRP->next_TRP;
    if (temp_TRP->next_TRP != nullptr)
        temp_TRP->next_TRP->prev_TRP = temp_TRP->prev_TRP;
    delete temp_TRP;
}

int main() {
    int choice_TRP, data_TRP, value_TRP;
    do {
        cout << "\n--- Doubly Linked List Operations ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert after value\n";
        cout << "4. Delete from Beginning\n5. Delete from End\n6. Delete specific value\n7. Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;
        switch (choice_TRP) {
            case 1:
                cout << "Enter data: ";
                cin >> data_TRP;
                insertAtBeginning_TRP(data_TRP);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data_TRP;
                insertAtEnd_TRP(data_TRP);
                break;
            case 3:
                cout << "Enter value after which to insert: ";
                cin >> value_TRP;
                cout << "Enter data: ";
                cin >> data_TRP;
                insertAfter_TRP(value_TRP, data_TRP);
                break;
            case 4:
                deleteFromBeginning_TRP();
                break;
            case 5:
                deleteFromEnd_TRP();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value_TRP;
                deleteValue_TRP(value_TRP);
                break;
            case 7:
                display_TRP();
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
--------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS19.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- Doubly Linked List Operations ---
1. Insert at Beginning
2. Insert at End
3. Insert after value
4. Delete from Beginning
5. Delete from End
6. Delete specific value
7. Display
0. Exit
Enter your choice: 1
Enter data: 10

Enter your choice: 2
Enter data: 20

Enter your choice: 2
Enter data: 30

Enter your choice: 3
Enter value after which to insert: 20
Enter data: 25

Enter your choice: 7
List: 10 20 25 30

Enter your choice: 4
(Deleted 10)

Enter your choice: 7
List: 20 25 30

Enter your choice: 6
Enter value to delete: 25

Enter your choice: 7
List: 20 30

Enter your choice: 5
(Deleted 30)

Enter your choice: 7
List: 20

Enter your choice: 0
Exiting...
