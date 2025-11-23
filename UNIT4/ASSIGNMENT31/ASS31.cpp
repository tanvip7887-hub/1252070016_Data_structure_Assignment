/*Write a program to perform Binary Search Tree (BST) operations (Create, Insert, Delete,Levelwise display )*/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {
    if(!root) return createNode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

Node* findMin(Node* root) {
    while(root && root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int data) {
    if(!root) return nullptr;
    if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if(data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if(!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void levelOrder(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    Node* root = nullptr;
    int choice, data;
    do {
        cout << "\n--- BST Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Level-wise Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data;
                root = insert(root, data);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> data;
                root = deleteNode(root, data);
                break;
            case 3:
                cout << "Level-wise traversal: ";
                levelOrder(root);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 0);
    return 0;
}
