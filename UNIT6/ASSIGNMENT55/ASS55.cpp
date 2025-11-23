/*WAP to simulate a faculty database as a hash table. Search a particular faculty by using MOD as a hash function for linear probing method 
of collision handling technique. Assume suitable data for faculty record.	*/


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










