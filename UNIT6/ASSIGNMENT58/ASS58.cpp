/*WAP to simulate employee databases as a hash table. Search a particular faculty by using Mid square method as a hash function for linear 
probing method of collision handling technique. Assume suitable data for faculty record.	*/

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
