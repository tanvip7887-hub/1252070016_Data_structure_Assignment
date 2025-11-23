
ASSIGNMENT 56
==============

AIM
----

WAP to simulate a faculty database as a hash table. Search a particular faculty by using 'divide' as a hash function for linear probing with chaining without replacement method of collision handling technique. Assume suitable data for faculty record.	


THEORY
-------

A hash table stores faculty records using Faculty ID as a key.
Divide method (modulo):
    index = Faculty_ID % Table_Size
A collision occurs when two faculty IDs map to the same index.

Linear Probing With Chaining (Without Replacement):
    Do not move an already placed record.
    If collision occurs, search linearly for the next empty slot.
    Store the new record in that free slot.
    Build a chain using a “next index pointer”.
    Only new keys get shifted; existing keys stay where they were.

Insert: Compute index → if occupied, probe forward → store at first empty → update chain link.
Search: Check original index → follow chain until ID is found.
Display: Print table indices, faculty details, and link pointer.


PROGRAM
--------

```CPP

#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 10

struct Faculty {
    int id;
    char name[20];
    int next;
};

Faculty table[SIZE];

// initialize table
void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i].id = -1;
        strcpy(table[i].name, "NULL");
        table[i].next = -1;
    }
}

int hashFunc(int id) {
    return id % SIZE;
}

void insertFaculty(int id, const char name[]) {
    int index = hashFunc(id);

    // Case 1: empty bucket available
    if (table[index].id == -1) {
        table[index].id = id;
        strcpy(table[index].name, name);
        cout << "Inserted at index " << index << endl;
        return;
    }

    // Case 2: collision → linear probing
    int i;
    for (i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;
        if (table[newIndex].id == -1) {   // empty found
            table[newIndex].id = id;
            strcpy(table[newIndex].name, name);

            // Find end of chain from original index
            int t = index;
            while (table[t].next != -1)
                t = table[t].next;

            table[t].next = newIndex;

            cout << "Inserted at index " << newIndex << " (collision handled)\n";
            return;
        }
    }

    cout << "Hash Table Full!\n";
}

void searchFaculty(int id) {
    int index = hashFunc(id);

    int t = index;
    while (t != -1) {
        if (table[t].id == id) {
            cout << "Faculty Found:\n";
            cout << "ID: " << table[t].id << "  Name: " << table[t].name << endl;
            return;
        }
        t = table[t].next;
    }
    cout << "Faculty Not Found!\n";
}

void display() {
    cout << "\n--- HASH TABLE ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        if (table[i].id == -1)
            cout << "Empty";
        else
            cout << table[i].id << " | " << table[i].name << " | next: " << table[i].next;
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
            cout << "Enter Faculty ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            insertFaculty(id, name);
            break;

        case 2:
            cout << "Enter ID to search: ";
            cin >> id;
            searchFaculty(id);
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
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS56.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

1.Insert
2.Search
3.Display
4.Exit
Enter choice: 1
Enter Faculty ID: 21
Enter Name: Amit
Inserted at index 1

Enter choice: 1
Enter Faculty ID: 31
Enter Name: Sneha
Inserted at index 2 (collision handled)

Enter choice: 1
Enter Faculty ID: 11
Enter Name: Raj
Inserted at index 1 (collision)
Inserted at index 3 (added to chain)

Enter choice: 3

--- HASH TABLE ---
0 : Empty
1 : 21 | Amit | next: 3
2 : 31 | Sneha | next: -1
3 : 11 | Raj | next: -1
4 : Empty
5 : Empty
6 : Empty
7 : Empty
8 : Empty
9 : Empty

Enter choice: 2
Enter ID to search: 11
Faculty Found:
ID: 11  Name: Raj
