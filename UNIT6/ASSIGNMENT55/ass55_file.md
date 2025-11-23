
ASSIGNMENT 55
==============

AIM 
-----

WAP to simulate a faculty database as a hash table. Search a particular faculty by using MOD as a hash function for linear probing method of collision handling technique. Assume suitable data for faculty record.			5	WAP to simulate a faculty database as a hash table. Search a particular faculty by using MOD as a hash function for linear probing method of collision handling technique. Assume suitable data for faculty record.	


THEORY
-------

A hash table stores faculty records such as ID and Name.
Hash Function:
    Index = Faculty_ID % Table_Size
A collision occurs when two faculty IDs map to the same index.
Linear Probing handles collisions by checking the next index: (index + 1) % Table_Size
Continue probing until an empty slot or the faculty record is found.

Insert: Compute index → if occupied, probe forward until empty location.
Search: Check hashed index → if not found, probe next indexes.
Display: Print table index and stored faculty ID + name.

Useful for fast searching using ID number.



PROGRAM
---------

```CPP

#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 10

struct Faculty {
    int id;
    char name[20];
};

Faculty table[SIZE];

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i].id = -1;     // empty slot
        strcpy(table[i].name, "NULL");
    }
}

int hashFunc(int id) {
    return id % SIZE;
}

void insertFaculty(int id, const char name[]) {
    int index = hashFunc(id);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (table[newIndex].id == -1) {  // Empty place found
            table[newIndex].id = id;
            strcpy(table[newIndex].name, name);
            cout << "Inserted at index " << newIndex << endl;
            return;
        }
    }

    cout << "Hash table is full! Cannot insert.\n";
}

void searchFaculty(int id) {
    int index = hashFunc(id);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (table[newIndex].id == id) {
            cout << "Faculty Found:\n";
            cout << "ID: " << table[newIndex].id << " Name: " << table[newIndex].name << endl;
            return;
        }
        if (table[newIndex].id == -1) break;  
    }

    cout << "Faculty not found.\n";
}

void display() {
    cout << "\n--- Faculty Hash Table ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        if (table[i].id == -1)
            cout << "Empty";
        else
            cout << table[i].id << " - " << table[i].name;
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

        switch(choice) {
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
            cout << "Invalid option\n";
        }
    }
}


```

OUTPUT
--------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS55.cpp

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
Inserted at index 2 (after linear probing)

Enter choice: 1
Enter Faculty ID: 14
Enter Name: Rakesh
Inserted at index 4

Enter choice: 3

--- Faculty Hash Table ---
0: Empty
1: 21 - Amit
2: 31 - Sneha
3: Empty
4: 14 - Rakesh
5: Empty
6: Empty
7: Empty
8: Empty
9: Empty

Enter choice: 2
Enter Faculty ID to search: 31
Faculty Found:
ID: 31 Name: Sneha


