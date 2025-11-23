/*Implement collision handling using separate chaining.	*/

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
