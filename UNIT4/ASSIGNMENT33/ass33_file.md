
ASSIGNMENT 33
==============

AIM - Write a Program to create a Binary Tree Search and Find Minimum/Maximum in BST 

THEORY
------

A Binary Search Tree (BST) is a special tree where every left child holds a smaller value and every right child holds a bigger value.
BST helps in fast searching, insertion, and deletion because elements are arranged in sorted order.
To find the minimum value in a BST, we keep moving to the leftmost node because the smallest element is always on the left side.
To find the maximum value in a BST, we keep moving to the rightmost node because the largest element is stored on the right side.
The program inserts values into the BST and maintains the sorted structure automatically using recursion.
In-order traversal is used to display the BST elements in ascending order.


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
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS33.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- BST Menu ---
1. Insert
2. Find Minimum
3. Find Maximum
4. In-order Display
0. Exit
Enter your choice: 1
Enter value to insert: 50

--- BST Menu ---
Enter your choice: 1
Enter value to insert: 30

--- BST Menu ---
Enter your choice: 1
Enter value to insert: 70

--- BST Menu ---
Enter your choice: 1
Enter value to insert: 20

--- BST Menu ---
Enter your choice: 1
Enter value to insert: 90

--- BST Menu ---
Enter your choice: 4
In-order traversal: 20 30 50 70 90

--- BST Menu ---
Enter your choice: 2
Minimum value: 20

--- BST Menu ---
Enter your choice: 3
Maximum value: 90

--- BST Menu ---
Enter your choice: 0
Exiting...
