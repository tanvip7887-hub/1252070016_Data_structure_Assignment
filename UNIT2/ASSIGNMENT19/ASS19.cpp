/*WAP to create a doubly linked list and perform following operations on it.A) Insert (all cases) 2. Delete (all cases).*/

#include <iostream>
using namespace std;

struct Node_TRP {
    int data_TRP;
    Node_TRP* prev_TRP;
    Node_TRP* next_TRP;
};

Node_TRP* head_TRP = nullptr;

Node_TRP* createNode_TRP(int data_TRP) {
    Node_TRP* newNode_TRP = new Node_TRP;
    newNode_TRP->data_TRP = data_TRP;
    newNode_TRP->prev_TRP = nullptr;
    newNode_TRP->next_TRP = nullptr;
    return newNode_TRP;
}

void display_TRP() {
    Node_TRP* temp_TRP = head_TRP;
    cout << "List: ";
    while (temp_TRP != nullptr) {
        cout << temp_TRP->data_TRP << " ";
        temp_TRP = temp_TRP->next_TRP;
    }
    cout << endl;
}

void insertAtBeginning_TRP(int data_TRP) {
    Node_TRP* newNode_TRP = createNode_TRP(data_TRP);
    if (head_TRP == nullptr) {
        head_TRP = newNode_TRP;
        return;
    }
    newNode_TRP->next_TRP = head_TRP;
    head_TRP->prev_TRP = newNode_TRP;
    head_TRP = newNode_TRP;
}

void insertAtEnd_TRP(int data_TRP) {
    Node_TRP* newNode_TRP = createNode_TRP(data_TRP);
    if (head_TRP == nullptr) {
        head_TRP = newNode_TRP;
        return;
    }
    Node_TRP* temp_TRP = head_TRP;
    while (temp_TRP->next_TRP != nullptr) {
        temp_TRP = temp_TRP->next_TRP;
    }
    temp_TRP->next_TRP = newNode_TRP;
    newNode_TRP->prev_TRP = temp_TRP;
}

void insertAfter_TRP(int value_TRP, int data_TRP) {
    Node_TRP* temp_TRP = head_TRP;
    while (temp_TRP != nullptr && temp_TRP->data_TRP != value_TRP) {
        temp_TRP = temp_TRP->next_TRP;
    }
    if (temp_TRP == nullptr) {
        cout << "Value not found!\n";
        return;
    }
    Node_TRP* newNode_TRP = createNode_TRP(data_TRP);
    newNode_TRP->next_TRP = temp_TRP->next_TRP;
    newNode_TRP->prev_TRP = temp_TRP;
    if (temp_TRP->next_TRP != nullptr)
        temp_TRP->next_TRP->prev_TRP = newNode_TRP;
    temp_TRP->next_TRP = newNode_TRP;
}

void deleteFromBeginning_TRP() {
    if (head_TRP == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    Node_TRP* temp_TRP = head_TRP;
    head_TRP = head_TRP->next_TRP;
    if (head_TRP != nullptr)
        head_TRP->prev_TRP = nullptr;
    delete temp_TRP;
}

void deleteFromEnd_TRP() {
    if (head_TRP == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    Node_TRP* temp_TRP = head_TRP;
    while (temp_TRP->next_TRP != nullptr) {
        temp_TRP = temp_TRP->next_TRP;
    }
    if (temp_TRP->prev_TRP != nullptr)
        temp_TRP->prev_TRP->next_TRP = nullptr;
    else
        head_TRP = nullptr;
    delete temp_TRP;
}

void deleteValue_TRP(int value_TRP) {
    Node_TRP* temp_TRP = head_TRP;
    while (temp_TRP != nullptr && temp_TRP->data_TRP != value_TRP) {
        temp_TRP = temp_TRP->next_TRP;
    }
    if (temp_TRP == nullptr) {
        cout << "Value not found!\n";
        return;
    }
    if (temp_TRP->prev_TRP != nullptr)
        temp_TRP->prev_TRP->next_TRP = temp_TRP->next_TRP;
    else
        head_TRP = temp_TRP->next_TRP;
    if (temp_TRP->next_TRP != nullptr)
        temp_TRP->next_TRP->prev_TRP = temp_TRP->prev_TRP;
    delete temp_TRP;
}

int main() {
    int choice_TRP, data_TRP, value_TRP;
    do {
        cout << "\n--- Doubly Linked List Operations ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert after value\n";
        cout << "4. Delete from Beginning\n5. Delete from End\n6. Delete specific value\n7. Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;
        switch (choice_TRP) {
            case 1:
                cout << "Enter data: ";
                cin >> data_TRP;
                insertAtBeginning_TRP(data_TRP);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data_TRP;
                insertAtEnd_TRP(data_TRP);
                break;
            case 3:
                cout << "Enter value after which to insert: ";
                cin >> value_TRP;
                cout << "Enter data: ";
                cin >> data_TRP;
                insertAfter_TRP(value_TRP, data_TRP);
                break;
            case 4:
                deleteFromBeginning_TRP();
                break;
            case 5:
                deleteFromEnd_TRP();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value_TRP;
                deleteValue_TRP(value_TRP);
                break;
            case 7:
                display_TRP();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice_TRP != 0);

    return 0;
}
