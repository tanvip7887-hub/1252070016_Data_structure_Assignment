/*Implement a hash table with collision resolution using linear probing.*/

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
