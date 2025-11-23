
ASSIGNMENT 52
===============

AIM - Implement collision handling using separate chaining.	

THEORY
-------

A hash table stores data in an array using a hash function.
Hash function: Index = Key % Table_Size
A collision occurs when two keys map to the same index.
Separate chaining handles collisions by storing all elements of the same index in a linked list (chain).

Insert: Compute hash index, create a new node, and insert it at the beginning of the linked list.
Search: Traverse the linked list at the hashed index until the key is found or the chain ends.
Display: Print all indices along with the linked list present at each index.

Efficient for handling multiple collisions and simple to implement.


PROGRAM
---------

```CPP

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

#define SIZE 10

Node* hashTable[SIZE];

// Initialize hash table
void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;
}

// Hash function
int hashFunc(int key) {
    return key % SIZE;
}

// Insert using separate chaining
void insertKey(int key) {
    int index = hashFunc(key);

    Node* newNode = new Node;
    newNode->data = key;
    newNode->next = NULL;

    // Insert at beginning of chain
    if (hashTable[index] == NULL)
        hashTable[index] = newNode;
    else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }

    cout << key << " inserted successfully.\n";
}

// Search key
bool searchKey(int key) {
    int index = hashFunc(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }

    return false;
}

// Display table
void display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " --> ";
        Node* temp = hashTable[i];

        if (temp == NULL)
            cout << "empty";

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    initialize();
    int choice, key;

    do {
        cout << "\n--- Hash Table Menu ---\n";
        cout << "1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            insertKey(key);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (searchKey(key))
                cout << key << " found.\n";
            else
                cout << key << " not found.\n";
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}


```


OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS52.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- Hash Table Menu ---
1. Insert
2. Search
3. Display
4. Exit
Enter your choice: 1
Enter key to insert: 15
15 inserted successfully.

--- Hash Table Menu ---
Enter your choice: 1
Enter key to insert: 25
25 inserted successfully.

--- Hash Table Menu ---
Enter your choice: 1
Enter key to insert: 35
35 inserted successfully.

--- Hash Table Menu ---
Enter your choice: 3

Hash Table:
0 --> empty NULL
1 --> empty NULL
2 --> empty NULL
3 --> empty NULL
4 --> empty NULL
5 --> 35 -> 25 -> 15 -> NULL
6 --> empty NULL
7 --> empty NULL
8 --> empty NULL
9 --> empty NULL

--- Hash Table Menu ---
Enter your choice: 2
Enter key to search: 25
25 found.

--- Hash Table Menu ---
Enter your choice: 4
Exiting...
