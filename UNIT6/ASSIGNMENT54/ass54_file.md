
ASSIGNMENT 54
==============

AIM - Store and retrieve student records using roll numbers.	


THEORY
-------

A hash table stores student records using roll number as the key.
Hash function: index = roll_no % table_size
If two roll numbers map to the same index → collision occurs.
Collision is handled using a linked list at each index (separate chaining).

Each node stores:
    roll number
    student name
    next pointer

Insert: Compute index → add record to linked list at that position.
Search: Traverse linked list at the index using roll number.
Display: Show all student records stored at each hash index.

Fast search because hashing directly points to the correct index.


PROGRAM
---------

```CPP
#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    int roll;
    char name[20];
    Student* next;
};

const int TABLE_SIZE = 10;
Student* hashTable[TABLE_SIZE];

void init() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;
}

int hashFunction(int roll) {
    return roll % TABLE_SIZE;
}

void insertRecord(int roll, const char name[]) {
    int index = hashFunction(roll);

    Student* newNode = new Student;
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->next = hashTable[index];

    hashTable[index] = newNode;

    cout << "Record inserted at index " << index << endl;
}

void searchRecord(int roll) {
    int index = hashFunction(roll);
    Student* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->roll == roll) {
            cout << "Record Found:\n";
            cout << "Roll No: " << temp->roll << "\nName: " << temp->name << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Record not found!" << endl;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        Student* temp = hashTable[i];
        while (temp != NULL) {
            cout << "[" << temp->roll << ", " << temp->name << "] -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    init();
    int choice, roll;
    char name[20];

    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Display\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter roll number: ";
            cin >> roll;
            cout << "Enter name: ";
            cin >> name;
            insertRecord(roll, name);
            break;

        case 2:
            cout << "Enter roll number to search: ";
            cin >> roll;
            searchRecord(roll);
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}


```

OUTPUT
--------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS54.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

1.Insert
2.Search
3.Display
4.Exit
Enter choice: 1
Enter roll number: 21
Enter name: Rahul
Record inserted at index 1

Enter choice: 1
Enter roll number: 31
Enter name: Asha
Record inserted at index 1   (collision handled using chaining)

Enter choice: 1
Enter roll number: 12
Enter name: Meera
Record inserted at index 2

Enter choice: 3
Index 0: NULL
Index 1: [31, Asha] -> [21, Rahul] -> NULL
Index 2: [12, Meera] -> NULL
Index 3: NULL
Index 4: NULL
Index 5: NULL
Index 6: NULL
Index 7: NULL
Index 8: NULL
Index 9: NULL

Enter choice: 2
Enter roll number to search: 31
Record Found:
Roll No: 31
Name: Asha
