
ASSIGNMENT 31
==============

AIM - Write a program to perform Binary Search Tree (BST) operations (Create, Insert, Delete,Levelwise display )

THEORY
-------

A Binary Search Tree (BST) is a special type of binary tree where every left child contains a value less than its parent and every right child contains a value greater than its parent. BST supports efficient searching, insertion, and deletion because of its sorted structure.

Insert: A new value is placed at the correct position by comparing it recursively with existing nodes.
Delete: A node can be deleted in three cases — leaf node, node with one child, or node with two children (replace with inorder successor).
Level-wise Display: Also called Level Order Traversal, it uses a queue to print nodes level by level from top to bottom.

BST helps maintain sorted data and allows faster operations compared to normal lists.


PROGRAM
--------

```CPP
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
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS31.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- BST Menu ---
1. Insert
2. Delete
3. Level-wise Display
0. Exit
Enter your choice: 1
Enter value to insert: 50

Enter your choice: 1
Enter value to insert: 30

Enter your choice: 1
Enter value to insert: 70

Enter your choice: 1
Enter value to insert: 20

Enter your choice: 1
Enter value to insert: 40

Enter your choice: 3
Level-wise traversal: 50 30 70 20 40

Enter your choice: 2
Enter value to delete: 30

Enter your choice: 3
Level-wise traversal: 50 40 70 20

Enter your choice: 1
Enter value to insert: 90

Enter your choice: 3
Level-wise traversal: 50 40 70 20 90

Enter your choice: 0
Exiting...
