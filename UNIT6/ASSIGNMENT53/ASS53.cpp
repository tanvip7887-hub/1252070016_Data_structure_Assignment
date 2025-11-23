/*Implement collision resolution using linked lists.	*/

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
