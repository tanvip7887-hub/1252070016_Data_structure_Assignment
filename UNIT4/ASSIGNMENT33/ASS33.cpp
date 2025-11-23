/*Write a Program to create a Binary Tree Search and Find Minimum/Maximum in BST */

#include <iostream>
using namespace std;

struct Node_TRP {
    int data_TRP;
    Node_TRP* left_TRP;
    Node_TRP* right_TRP;
};

Node_TRP* createNode_TRP(int data_TRP) {
    Node_TRP* newNode_TRP = new Node_TRP;
    newNode_TRP->data_TRP = data_TRP;
    newNode_TRP->left_TRP = newNode_TRP->right_TRP = nullptr;
    return newNode_TRP;
}

Node_TRP* insert_TRP(Node_TRP* root_TRP, int data_TRP) {
    if(!root_TRP) return createNode_TRP(data_TRP);
    if(data_TRP < root_TRP->data_TRP)
        root_TRP->left_TRP = insert_TRP(root_TRP->left_TRP, data_TRP);
    else
        root_TRP->right_TRP = insert_TRP(root_TRP->right_TRP, data_TRP);
    return root_TRP;
}

int findMin_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return -1;
    while(root_TRP->left_TRP) root_TRP = root_TRP->left_TRP;
    return root_TRP->data_TRP;
}

int findMax_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return -1;
    while(root_TRP->right_TRP) root_TRP = root_TRP->right_TRP;
    return root_TRP->data_TRP;
}

void inorder_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return;
    inorder_TRP(root_TRP->left_TRP);
    cout << root_TRP->data_TRP << " ";
    inorder_TRP(root_TRP->right_TRP);
}

int main() {
    Node_TRP* root_TRP = nullptr;
    int choice_TRP, data_TRP;
    do {
        cout << "\n--- BST Menu ---\n";
        cout << "1. Insert\n2. Find Minimum\n3. Find Maximum\n4. In-order Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;
        switch(choice_TRP) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data_TRP;
                root_TRP = insert_TRP(root_TRP, data_TRP);
                break;
            case 2:
                if(root_TRP)
                    cout << "Minimum value: " << findMin_TRP(root_TRP) << endl;
                else
                    cout << "BST is empty\n";
                break;
            case 3:
                if(root_TRP)
                    cout << "Maximum value: " << findMax_TRP(root_TRP) << endl;
                else
                    cout << "BST is empty\n";
                break;
            case 4:
                cout << "In-order traversal: ";
                inorder_TRP(root_TRP);
                cout << endl;
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice_TRP != 0);

    return 0;
}
