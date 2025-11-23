
ASSIGNMENT 58
===============

AIM
----

WAP to simulate employee databases as a hash table. Search a particular faculty by using Mid square method as a hash function for linear probing method of collision handling technique. Assume suitable data for faculty record.	


THEORY
--------

A hash table stores employee records using Employee ID as a key.
Mid-Square Hash Function:
Square the key
Extract the middle digit(s)
Take modulo table size to get index

Formula:
    index = (middle digits of (ID × ID)) % Table_Size
A collision occurs when two IDs map to the same index.

Linear Probing:
    If collision occurs, move to next index (index + 1) % Table_Size
    Continue until an empty slot is found

Insert: Use mid-square to get index → if occupied → probe until empty.
Search: Start at hashed index → linearly probe until key is found or all slots checked.
Display: Show index and employee details.


PROGRAM
--------

```CPP

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define SIZE 10

struct Employee {
    int id;
    char name[20];
};

Employee table[SIZE];

// initialize table
void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i].id = -1;
        strcpy(table[i].name, "NULL");
    }
}

// mid-square hash function
int midSquare(int id) {
    long long sq = (long long)id * id;

    // extract middle digit(s)
    int middle = (sq / 10) % 100;   // extracting 2 middle digits

    return middle % SIZE;
}

// insert employee
void insertEmp(int id, const char name[]) {
    int index = midSquare(id);

    if (table[index].id == -1) {
        table[index].id = id;
        strcpy(table[index].name, name);
        cout << "Inserted at index " << index << endl;
        return;
    }

    // collision → linear probing
    for (int i = 1; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (table[newIndex].id == -1) {
            table[newIndex].id = id;
            strcpy(table[newIndex].name, name);
            cout << "Inserted at index " << newIndex << " (collision handled)\n";
            return;
        }
    }

    cout << "Hash Table Full!\n";
}

// search employee
void searchEmp(int id) {
    int index = midSquare(id);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (table[newIndex].id == id) {
            cout << "Employee Found:\n";
            cout << "ID: " << table[newIndex].id << " Name: " << table[newIndex].name << endl;
            return;
        }
    }

    cout << "Employee Not Found!\n";
}

// display table
void display() {
    cout << "\n--- HASH TABLE ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        if (table[i].id == -1)
            cout << "Empty";
        else
            cout << table[i].id << " | " << table[i].name;
        cout << endl;
    }
}

int main() {
    init();

    int choice, id;
    char name[20];

    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Display\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            insertEmp(id, name);
            break;

        case 2:
            cout << "Enter ID to search: ";
            cin >> id;
            searchEmp(id);
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}

```


OUTPUT
--------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS58.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

1.Insert
2.Search
3.Display
4.Exit
Enter choice: 1
Enter Employee ID: 23
Enter Name: Amit
Inserted at index 2

Enter choice: 1
Enter Employee ID: 45
Enter Name: Neha
Inserted at index 0

Enter choice: 1
Enter Employee ID: 67
Enter Name: Sam
Inserted at index 9

Enter choice: 3

--- HASH TABLE ---
0 : 45 | Neha
1 : Empty
2 : 23 | Amit
3 : Empty
4 : Empty
5 : Empty
6 : Empty
7 : Empty
8 : Empty
9 : 67 | Sam

Enter choice: 2
Enter ID to search: 23
Employee Found:
ID: 23  Name: Amit
