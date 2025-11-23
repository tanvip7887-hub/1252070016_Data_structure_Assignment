/*	Store and retrieve student records using roll numbers.	*/

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
