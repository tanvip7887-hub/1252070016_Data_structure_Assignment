
ASSIGNMENT 35
==============

AIM
----

Write a Program to create a Binary Tree and perform the following Recursive operations on it. 
a. Inorder Traversal 
b. Preorder Traversal 
c. Display Number of Leaf Nodes 
d. Mirror Image


THEORY
-------

A Binary Tree is a hierarchical structure where each node has a left child and a right child.
Recursive traversal uses function calls to visit nodes automatically based on tree structure.
Inorder Traversal (Left → Root → Right) is implemented using recursion to explore left subtree first.
Preorder Traversal (Root → Left → Right) processes the node before visiting its children.
Leaf nodes are counted by checking nodes that have no left and right child, using recursive calls.
Mirror Image of a binary tree is created by recursively swapping the left and right child of every node.


PROGRAM
--------

```CPP
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
    if(!root_TRP->left_TRP) root_TRP->left_TRP = insert_TRP(root_TRP->left_TRP, data_TRP);
    else root_TRP->right_TRP = insert_TRP(root_TRP->right_TRP, data_TRP);
    return root_TRP;
}

void inorder_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return;
    inorder_TRP(root_TRP->left_TRP);
    cout << root_TRP->data_TRP << " ";
    inorder_TRP(root_TRP->right_TRP);
}

void preorder_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return;
    cout << root_TRP->data_TRP << " ";
    preorder_TRP(root_TRP->left_TRP);
    preorder_TRP(root_TRP->right_TRP);
}

int countLeafNodes_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return 0;
    if(!root_TRP->left_TRP && !root_TRP->right_TRP) return 1;
    return countLeafNodes_TRP(root_TRP->left_TRP) + countLeafNodes_TRP(root_TRP->right_TRP);
}

void mirror_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return;
    swap(root_TRP->left_TRP, root_TRP->right_TRP);
    mirror_TRP(root_TRP->left_TRP);
    mirror_TRP(root_TRP->right_TRP);
}

int main() {
    Node_TRP* root_TRP = nullptr;
    int choice_TRP, data_TRP;
    do {
        cout << "\n--- Binary Tree Menu ---\n";
        cout << "1. Insert Node\n2. Inorder Traversal\n3. Preorder Traversal\n4. Count Leaf Nodes\n5. Mirror Image\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;
        switch(choice_TRP) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data_TRP;
                root_TRP = insert_TRP(root_TRP, data_TRP);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder_TRP(root_TRP);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder_TRP(root_TRP);
                cout << endl;
                break;
            case 4:
                cout << "Number of leaf nodes: " << countLeafNodes_TRP(root_TRP) << endl;
                break;
            case 5:
                mirror_TRP(root_TRP);
                cout << "Mirror image created.\n";
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
```

OUTPUT
------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS35cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- Binary Tree Menu ---
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Count Leaf Nodes
5. Mirror Image
0. Exit
Enter your choice: 1
Enter value to insert: 10

--- Binary Tree Menu ---
Enter your choice: 1
Enter value to insert: 20

--- Binary Tree Menu ---
Enter your choice: 1
Enter value to insert: 30

--- Binary Tree Menu ---
Enter your choice: 2
Inorder Traversal: 20 10 30

--- Binary Tree Menu ---
Enter your choice: 3
Preorder Traversal: 10 20 30

--- Binary Tree Menu ---
Enter your choice: 4
Number of leaf nodes: 1

--- Binary Tree Menu ---
Enter your choice: 5
Mirror image created.

--- Binary Tree Menu ---
Enter your choice: 2
Inorder Traversal: 30 10 20

--- Binary Tree Menu ---
Enter your choice: 0
Exiting...

