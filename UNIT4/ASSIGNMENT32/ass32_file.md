
ASSIGNMENT 32
==============

AIM
----
Write a program to perform Binary Search Tree (BST) operations (Count the total number of nodes, Compute the height of the BST, Mirror Image ).

THEORY
-------

A Binary Search Tree (BST) is a special tree where every left child has a smaller value than its parent and every right child has a larger value.
Counting nodes in a BST helps to know the total number of elements stored in the tree structure.
The height of a BST shows the longest path from the root to any leaf, which helps understand how balanced the tree is.
The height is computed using recursion by checking the height of the left and right subtrees and taking the maximum.
The mirror image of a BST is formed by swapping the left and right child nodes at every level of the tree.
Mirroring a BST helps understand tree transformations and is useful in various tree-based applications.


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
    if(data_TRP < root_TRP->data_TRP)
        root_TRP->left_TRP = insert_TRP(root_TRP->left_TRP, data_TRP);
    else
        root_TRP->right_TRP = insert_TRP(root_TRP->right_TRP, data_TRP);
    return root_TRP;
}

int countNodes_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return 0;
    return 1 + countNodes_TRP(root_TRP->left_TRP) + countNodes_TRP(root_TRP->right_TRP);
}

int height_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return 0;
    int lh_TRP = height_TRP(root_TRP->left_TRP);
    int rh_TRP = height_TRP(root_TRP->right_TRP);
    return 1 + max(lh_TRP, rh_TRP);
}

void mirror_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return;
    swap(root_TRP->left_TRP, root_TRP->right_TRP);
    mirror_TRP(root_TRP->left_TRP);
    mirror_TRP(root_TRP->right_TRP);
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
        cout << "\n--- BST Operations ---\n";
        cout << "1. Insert\n2. Count nodes\n3. Compute height\n4. Mirror Image\n5. In-order Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;
        switch(choice_TRP) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data_TRP;
                root_TRP = insert_TRP(root_TRP, data_TRP);
                break;
            case 2:
                cout << "Total nodes: " << countNodes_TRP(root_TRP) << endl;
                break;
            case 3:
                cout << "Height of BST: " << height_TRP(root_TRP) << endl;
                break;
            case 4:
                mirror_TRP(root_TRP);
                cout << "BST has been mirrored.\n";
                break;
            case 5:
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
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS32.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- BST Operations ---
1. Insert
2. Count nodes
3. Compute height
4. Mirror Image
5. In-order Display
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

Enter your choice: 5
In-order traversal: 20 30 40 50 70

Enter your choice: 2
Total nodes: 5

Enter your choice: 3
Height of BST: 3

Enter your choice: 4
BST has been mirrored.

Enter your choice: 5
In-order traversal: 70 50 40 30 20

Enter your choice: 0
Exiting...
