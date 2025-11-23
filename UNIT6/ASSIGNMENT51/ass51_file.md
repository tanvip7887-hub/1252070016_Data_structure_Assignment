
ASSIGNMENT 51
==============

AIM - Implement a hash table with collision resolution using linear probing.

THEORY
--------

Definition: Stores data in an array using a hash function to map keys to indices.

Hash Function: Index = Key % Table_Size
Collision: Occurs when two keys map to the same index.
Collision Resolution (Linear Probing):

Move to next index (index + 1) % Table_Size until empty.
Wrap around if needed.

Operations:
    Insert: Add key at hashed or next empty index.
    Search: Check hashed index; probe if not found.
    Display: Show table indices and stored keys.

Implementation:
    Uses a fixed-size array.
    -1 indicates empty slot.
    Menu-driven program for insert, search, display, exit.


PROGRAM
--------

```CPP

#include <iostream>
using namespace std;

#define MAX 10

int hashTable[MAX];

// Initialize hash table
void initialize() {
    for (int i = 0; i < MAX; i++)
        hashTable[i] = -1; // -1 indicates empty
}

// Hash function
int hashFunc(int key) {
    return key % MAX;
}

// Insert key using linear probing
void insert(int key) {
    int index = hashFunc(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % MAX;
        if (index == startIndex) {
            cout << "Hash table full. Cannot insert " << key << endl;
            return;
        }
    }
    hashTable[index] = key;
    cout << key << " inserted successfully." << endl;
}

// Search key
bool search(int key) {
    int index = hashFunc(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return true;
        index = (index + 1) % MAX;
        if (index == startIndex)
            break;
    }
    return false;
}

// Display hash table
void display() {
    cout << "\nHash Table:" << endl;
    for (int i = 0; i < MAX; i++) {
        if (hashTable[i] != -1)
            cout << i << " --> " << hashTable[i] << endl;
        else
            cout << i << " --> empty" << endl;
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
            insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (search(key))
                cout << key << " found in hash table." << endl;
            else
                cout << key << " not found in hash table." << endl;
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS51.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- Hash Table Menu ---
1. Insert
2. Search
3. Display
4. Exit
Enter your choice: 1
Enter key to insert: 5
5 inserted successfully.

Enter your choice: 1
Enter key to insert: 15
15 inserted successfully.

Enter your choice: 1
Enter key to insert: 25
25 inserted successfully.

Enter your choice: 1
Enter key to insert: 35
35 inserted successfully.

Enter your choice: 3

Hash Table:
0 --> empty
1 --> empty
2 --> empty
3 --> empty
4 --> empty
5 --> 5
6 --> 15
7 --> 25
8 --> 35
9 --> empty

Enter your choice: 2
Enter key to search: 25
25 found in hash table.

Enter your choice: 4
Exiting...
