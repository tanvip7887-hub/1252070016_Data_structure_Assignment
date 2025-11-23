
ASSIGNMENT 53
===============

AIM - Implement collision resolution using linked lists.

THEORY 
-------

A hash table stores data in an array using a hash function.
Hash function used: index = key % table_size
When two keys map to the same index → collision.
Linked list is used at each index to store multiple values → called separate chaining.

Insert: Find index using hash function, create a node, attach it to the linked list at that index.
Search: Traverse the linked list at that index to find the key.
Display: Show all indices and their linked lists.

Easy to handle multiple collisions because each index can grow using linked list


PROGRAM
--------

```CPP

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

const int TABLE_SIZE = 10;
Node* hashTable[TABLE_SIZE];

// Initialize table
void init() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert element
void insert(int key) {
    int index = hashFunction(key);

    Node* newNode = new Node;
    newNode->data = key;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;

    cout << "Inserted " << key << " at index " << index << endl;
}

// Search element
void search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key) {
            cout << key << " found at index " << index << endl;
            return;
        }
        temp = temp->next;
    }

    cout << key << " not found" << endl;
}

// Display table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        Node* temp = hashTable[i];
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    init();

    int choice, key;
    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Display\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            insert(key);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            search(key);
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}


```

OUTPUT
--------


C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS53.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

1.Insert
2.Search
3.Display
4.Exit
Enter choice: 1
Enter key to insert: 25
Inserted 25 at index 5

Enter choice: 1
Enter key to insert: 35
Inserted 35 at index 5    (collision handled using linked list)

Enter choice: 1
Enter key to insert: 12
Inserted 12 at index 2

Enter choice: 3
Index 0: NULL
Index 1: NULL
Index 2: 12 -> NULL
Index 3: NULL
Index 4: NULL
Index 5: 35 -> 25 -> NULL
Index 6: NULL
Index 7: NULL
Index 8: NULL
Index 9: NULL

Enter choice: 2
Enter key to search: 35
35 found at index 5
