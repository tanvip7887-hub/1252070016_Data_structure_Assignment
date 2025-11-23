
ASSIGNMENT 37
==============

AIM
----

Write a program to illustrate operations on a BST holding numeric keys.
The menu must include: • Insert • Delete • Find • Show

THEORY
-------

A Binary Search Tree (BST) is a tree data structure where each node has a numeric key, and:
The left child contains keys less than the parent node.
The right child contains keys greater than the parent node.

Insertion: Adds a new node in the correct position maintaining the BST property.
Deletion: Removes a node while keeping the tree properly ordered.
Find/Search: Locates a node with a given key efficiently.
Traversal/Show: Displays the BST nodes in order (inorder, preorder, or postorder).


PROGRAM
--------

```CPP
#include <iostream>
#include <queue>
using namespace std;

struct Node_TRP 
{
    int key_TRP;
    Node_TRP* left_TRP;
    Node_TRP* right_TRP;
};

Node_TRP* createNode_TRP(int key_TRP) 
{
    Node_TRP* newNode_TRP = new Node_TRP;
    newNode_TRP->key_TRP = key_TRP;
    newNode_TRP->left_TRP = newNode_TRP->right_TRP = nullptr;
    return newNode_TRP;
}

Node_TRP* insert_TRP(Node_TRP* root_TRP, int key_TRP) 
{
    if(!root_TRP) 
    return createNode_TRP(key_TRP);

    if(key_TRP < root_TRP->key_TRP) 
    root_TRP->left_TRP = insert_TRP(root_TRP->left_TRP, key_TRP);
    else 
    if(key_TRP > root_TRP->key_TRP) 
    root_TRP->right_TRP = insert_TRP(root_TRP->right_TRP, key_TRP);

    return root_TRP;
}


Node_TRP* findMin_TRP(Node_TRP* root_TRP) 
{
    while(root_TRP && root_TRP->left_TRP) 
    root_TRP = root_TRP->left_TRP;

    return root_TRP;
}

Node_TRP* deleteNode_TRP(Node_TRP* root_TRP, int key_TRP) 
{
    if(!root_TRP) 
      return nullptr;

    if(key_TRP < root_TRP->key_TRP) 
       root_TRP->left_TRP = deleteNode_TRP(root_TRP->left_TRP, key_TRP);
    else if(key_TRP > root_TRP->key_TRP) 
    root_TRP->right_TRP = deleteNode_TRP(root_TRP->right_TRP, key_TRP);
    else 
    {
        if(!root_TRP->left_TRP) 
        {
            Node_TRP* temp_TRP = root_TRP->right_TRP; 
            delete root_TRP; 
            return temp_TRP; 
        }
        else if(!root_TRP->right_TRP) 
        {
             Node_TRP* temp_TRP = root_TRP->left_TRP; 
             delete root_TRP; return temp_TRP; 
        }
        else {
            Node_TRP* temp_TRP = findMin_TRP(root_TRP->right_TRP);
            root_TRP->key_TRP = temp_TRP->key_TRP;
            root_TRP->right_TRP = deleteNode_TRP(root_TRP->right_TRP, temp_TRP->key_TRP);
        }
    }
    return root_TRP;
}

bool find_TRP(Node_TRP* root_TRP, int key_TRP) {
    if(!root_TRP) return false;
    if(root_TRP->key_TRP == key_TRP) return true;
    if(key_TRP < root_TRP->key_TRP) return find_TRP(root_TRP->left_TRP, key_TRP);
    return find_TRP(root_TRP->right_TRP, key_TRP);
}

void inorder_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return;
    inorder_TRP(root_TRP->left_TRP);
    cout << root_TRP->key_TRP << " ";
    inorder_TRP(root_TRP->right_TRP);
}

int main() {
    Node_TRP* root_TRP = nullptr;
    int choice_TRP, key_TRP;
    do {
        cout << "\n--- BST Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Find\n4. Show (Inorder)\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;
        switch(choice_TRP) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key_TRP;
                root_TRP = insert_TRP(root_TRP, key_TRP);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key_TRP;
                root_TRP = deleteNode_TRP(root_TRP, key_TRP);
                break;
            case 3:
                cout << "Enter key to find: ";
                cin >> key_TRP;
                if(find_TRP(root_TRP, key_TRP)) cout << key_TRP << " found in BST.\n";
                else cout << key_TRP << " not found in BST.\n";
                break;
            case 4:
                cout << "Inorder traversal: ";
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

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS37.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- BST Menu ---
1. Insert
2. Delete
3. Find
4. Show (Inorder)
0. Exit
Enter your choice: 1
Enter key to insert: 50

--- BST Menu ---
1. Insert
2. Delete
3. Find
4. Show (Inorder)
0. Exit
Enter your choice: 1
Enter key to insert: 30

--- BST Menu ---
1. Insert
2. Delete
3. Find
4. Show (Inorder)
0. Exit
Enter your choice: 1
Enter key to insert: 70

--- BST Menu ---
1. Insert
2. Delete
3. Find
4. Show (Inorder)
0. Exit
Enter your choice: 4
Inorder traversal: 30 50 70 

--- BST Menu ---
1. Insert
2. Delete
3. Find
4. Show (Inorder)
0. Exit
Enter your choice: 3
Enter key to find: 50
50 found in BST.

--- BST Menu ---
1. Insert
2. Delete
3. Find
4. Show (Inorder)
0. Exit
Enter your choice: 2
Enter key to delete: 30

--- BST Menu ---
1. Insert
2. Delete
3. Find
4. Show (Inorder)
0. Exit
Enter your choice: 4
Inorder traversal: 50 70 

--- BST Menu ---
1. Insert
2. Delete
3. Find
4. Show (Inorder)
0. Exit
Enter your choice: 0
Exiting...
