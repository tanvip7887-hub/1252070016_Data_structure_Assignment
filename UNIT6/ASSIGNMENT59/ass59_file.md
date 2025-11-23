
ASSIGNMENT 59
==============

AIM
-----

WAP to simulate student databases as a hash table. a student database management system using hashing techniques to allow efficient insertion, search, and deletion of student records.


THEORY
-------

A hash table stores student records in an array using a hash function.
• Hash function maps roll number → index for fast access.
• We use: index = roll % TABLE_SIZE
• Collision occurs when two roll numbers map to the same index.
• Collision is handled using linear probing → move to next index
    (index + 1) % TABLE_SIZE

• Operations:
    – Insert → place student at empty slot after probing
    – Search → probe until roll found or table ends
    – Delete → mark slot as deleted using a special value

• Linear probing makes implementation simple and efficient for small datasets.
• Hashing provides fast search, insert, and delete operations.


PROGRAM
--------

```CPP

#include <iostream>
using namespace std;

#define SIZE 10

struct Student {
    int roll;
    string name;
};

Student table[SIZE];
int status[SIZE];  
// 0 = empty, 1 = occupied, 2 = deleted

int hashFunction(int roll) {
    return roll % SIZE;
}

void insertStudent() {
    int roll;
    string name;
    cout << "Enter Roll No: ";
    cin >> roll;
    cout << "Enter Name: ";
    cin >> name;

    int index = hashFunction(roll);
    int start = index;

    while (status[index] == 1) {
        index = (index + 1) % SIZE;
        if (index == start) {
            cout << "Table Full!\n";
            return;
        }
    }

    table[index].roll = roll;
    table[index].name = name;
    status[index] = 1;
    cout << "Student Inserted!\n";
}

void searchStudent() {
    int roll;
    cout << "Enter Roll No to Search: ";
    cin >> roll;

    int index = hashFunction(roll);
    int start = index;

    while (status[index] != 0) {
        if (status[index] == 1 && table[index].roll == roll) {
            cout << "Student Found at Index " << index << endl;
            cout << "Roll: " << table[index].roll << "  Name: " << table[index].name << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    cout << "Student Not Found!\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll No to Delete: ";
    cin >> roll;

    int index = hashFunction(roll);
    int start = index;

    while (status[index] != 0) {
        if (status[index] == 1 && table[index].roll == roll) {
            status[index] = 2;
            cout << "Record Deleted!\n";
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    cout << "Record Not Found!\n";
}

void displayTable() {
    cout << "\nIndex\tRoll\tName\n";
    for (int i = 0; i < SIZE; i++) {
        if (status[i] == 1)
            cout << i << "\t" << table[i].roll << "\t" << table[i].name << endl;
        else
            cout << i << "\t--\t--\n";
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) status[i] = 0;

    int choice;
    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: insertStudent(); break;
        case 2: searchStudent(); break;
        case 3: deleteStudent(); break;
        case 4: displayTable(); break;
        case 5: return 0;
        default: cout << "Invalid Choice!\n";
        }
    }
}


```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS59.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

1.Insert
2.Search
3.Delete
4.Display
5.Exit
Enter choice: 1
Enter Roll No: 15
Enter Name: Rahul
Student Inserted!

Enter choice: 1
Enter Roll No: 25
Enter Name: Sara
Student Inserted!

Enter choice: 4

Index   Roll    Name
0       --      --
1       --      --
2       12      Rahul
3       --      --
4       --      --
5       25      Sara
6       --      --
7       --      --
8       --      --
9       --      --

Enter choice: 2
Enter Roll No: 25
Student Found at Index 5
Roll: 25  Name: Sara


