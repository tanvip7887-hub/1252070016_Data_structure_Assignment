
ASSIGNMENT 57
=============

AIM
----

WAP to simulate a faculty database as a hash table. Search a particular faculty by using MOD as a hash function for linear probing with chaining with replacement method of collision handling technique. Assume suitable data for faculty record.	


THEORY
-------

A hash table stores faculty records using Faculty ID as a key.
MOD (divide) method used as hash function:
    index = Faculty_ID % Table_Size
A collision occurs when two IDs map to the same index.

Chaining WITH Replacement:
If a new key belongs to a bucket already occupied by a key that does NOT belong there,
    → Replace the old key with the new key.
Move the replaced (displaced) key to another free slot using linear probing.
Update chain links accordingly.

Insert Steps:
    Compute index.
    If empty → insert.

If collision:
    If existing key belongs to another index → swap (replace).
    Else linear probe for free slot.

Search: Traverse chain until ID is found.
Display: Show index, faculty details, and next pointer.


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

    // Case 1: empty slot
    if (table[index].id == -1) {
        table[index].id = id;
        strcpy(table[index].name, name);
        cout << "Inserted at index " << index << endl;
        return;
    }

    // Case 2: collision with replacement
    if (hashFunc(table[index].id) != index) {
        int displacedID = table[index].id;
        char displacedName[20];
        strcpy(displacedName, table[index].name);
        int displacedNext = table[index].next;

        table[index].id = id;
        strcpy(table[index].name, name);
        table[index].next = -1;

        cout << "Replaced existing record at index " << index << endl;

        // Insert displaced element again
        insertFaculty(displacedID, displacedName);
        return;
    }

    // Case 3: same home → linear probing
    for (int i = 1; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;
        if (table[newIndex].id == -1) {
            table[newIndex].id = id;
            strcpy(table[newIndex].name, name);

            // Link chaining
            int t = index;
            while (table[t].next != -1)
                t = table[t].next;

            table[t].next = newIndex;

            cout << "Inserted at index " << newIndex << " (linear probe)\n";
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
            cout << "ID: " << table[t].id << " Name: " << table[t].name << endl;
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
            cout << "Enter Faculty ID to search: ";
            cin >> id;
            searchFaculty(id);
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
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS57.cpp

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
Inserted at index 1 (collision)
Replaced existing record at index 1
Inserted at index 2 (reinserted old record)

Enter choice: 1
Enter Faculty ID: 11
Enter Name: Riya
Inserted at index 1 (linear probe)
Inserted at index 3

Enter choice: 3

--- HASH TABLE ---
0 : Empty
1 : 31 | Sneha | next: 3
2 : 21 | Amit | next: -1
3 : 11 | Riya | next: -1
4 : Empty
5 : Empty
6 : Empty
7 : Empty
8 : Empty
9 : Empty

Enter choice: 2
Enter Faculty ID to search: 11
Faculty Found:
ID: 11 Name: Riya
