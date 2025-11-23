
ASSIGNMENT 39
==============

AIM
----

Write a program to implement a product inventory management system for a shop using a search tree data structure. 
Each product must store the following information:
    ●	Unique Product Code
    ●	Product Name
    ●	Price
    ●	Quantity in Stock
    ●	Date Received
    ●	Expiration Date
Implement the following operations:
    1.	Insert a product into the tree ( organized by product name).
    2.	Display all items in the inventory using inorder traversal.
    3.	List expired items in prefix (preorder) order of their names.


THEORY
-------

A Binary Search Tree (BST) is used to efficiently store and manage product records.

Each node contains:
Unique Product Code
Product Name
Price
Quantity in Stock
Date Received
Expiration Date

Insertion: Adds products to the tree, organized by product name.
Inorder Traversal: Displays products in alphabetical order of names.
Preorder Traversal for Expired Items: Lists expired products quickly for stock management.


PROGRAM
--------

```CPP
#include <iostream>
#include <string>
using namespace std;

struct Product_TRP {
    string code_TRP;
    string name_TRP;
    double price_TRP;
    int quantity_TRP;
    string dateReceived_TRP;
    string expiryDate_TRP;
    Product_TRP* left_TRP;
    Product_TRP* right_TRP;
};

Product_TRP* createProduct_TRP(string code_TRP, string name_TRP, double price_TRP, int quantity_TRP, string dateReceived_TRP, string expiryDate_TRP) {
    Product_TRP* p_TRP = new Product_TRP;
    p_TRP->code_TRP = code_TRP;
    p_TRP->name_TRP = name_TRP;
    p_TRP->price_TRP = price_TRP;
    p_TRP->quantity_TRP = quantity_TRP;
    p_TRP->dateReceived_TRP = dateReceived_TRP;
    p_TRP->expiryDate_TRP = expiryDate_TRP;
    p_TRP->left_TRP = p_TRP->right_TRP = nullptr;
    return p_TRP;
}

Product_TRP* insert_TRP(Product_TRP* root_TRP, Product_TRP* p_TRP) {
    if(!root_TRP) return p_TRP;
    if(p_TRP->name_TRP < root_TRP->name_TRP)
        root_TRP->left_TRP = insert_TRP(root_TRP->left_TRP, p_TRP);
    else
        root_TRP->right_TRP = insert_TRP(root_TRP->right_TRP, p_TRP);
    return root_TRP;
}

void inorder_TRP(Product_TRP* root_TRP) {
    if(!root_TRP) return;
    inorder_TRP(root_TRP->left_TRP);
    cout << "Code: " << root_TRP->code_TRP 
         << ", Name: " << root_TRP->name_TRP 
         << ", Price: " << root_TRP->price_TRP 
         << ", Quantity: " << root_TRP->quantity_TRP 
         << ", Received: " << root_TRP->dateReceived_TRP 
         << ", Expiry: " << root_TRP->expiryDate_TRP << endl;
    inorder_TRP(root_TRP->right_TRP);
}

void preorderExpired_TRP(Product_TRP* root_TRP, string currentDate_TRP) {
    if(!root_TRP) return;
    if(root_TRP->expiryDate_TRP < currentDate_TRP)
        cout << "Expired - Code: " << root_TRP->code_TRP 
             << ", Name: " << root_TRP->name_TRP 
             << ", Expiry: " << root_TRP->expiryDate_TRP << endl;
    preorderExpired_TRP(root_TRP->left_TRP, currentDate_TRP);
    preorderExpired_TRP(root_TRP->right_TRP, currentDate_TRP);
}

int main() {
    Product_TRP* root_TRP = nullptr;
    int choice_TRP, quantity_TRP;
    double price_TRP;
    string code_TRP, name_TRP, dateReceived_TRP, expiryDate_TRP, currentDate_TRP;

    do {
        cout << "\n--- Product Inventory Menu ---\n";
        cout << "1. Insert Product\n2. Display Inventory (Inorder)\n3. List Expired Products (Preorder)\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;

        switch(choice_TRP) {
            case 1:
                cout << "Enter Product Code: "; cin >> code_TRP;
                cout << "Enter Product Name: "; cin >> ws; getline(cin, name_TRP);
                cout << "Enter Price: "; cin >> price_TRP;
                cout << "Enter Quantity: "; cin >> quantity_TRP;
                cout << "Enter Date Received (YYYY-MM-DD): "; cin >> dateReceived_TRP;
                cout << "Enter Expiration Date (YYYY-MM-DD): "; cin >> expiryDate_TRP;
                root_TRP = insert_TRP(root_TRP, createProduct_TRP(code_TRP, name_TRP, price_TRP, quantity_TRP, dateReceived_TRP, expiryDate_TRP));
                break;

            case 2:
                cout << "\nInventory Items (sorted by name):\n";
                inorder_TRP(root_TRP);
                break;

            case 3:
                cout << "Enter current date (YYYY-MM-DD) to check expired items: ";
                cin >> currentDate_TRP;
                cout << "\nExpired Products:\n";
                preorderExpired_TRP(root_TRP, currentDate_TRP);
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

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS39.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- Product Inventory Menu ---
1. Insert Product
2. Display Inventory (Inorder)
3. List Expired Products (Preorder)
0. Exit
Enter your choice: 1
Enter Product Code: P101
Enter Product Name: Milk
Enter Price: 50
Enter Quantity: 20
Enter Date Received (YYYY-MM-DD): 2025-11-01
Enter Expiration Date (YYYY-MM-DD): 2025-11-10

--- Product Inventory Menu ---
1. Insert Product
2. Display Inventory (Inorder)
3. List Expired Products (Preorder)
0. Exit
Enter your choice: 1
Enter Product Code: P102
Enter Product Name: Bread
Enter Price: 30
Enter Quantity: 15
Enter Date Received (YYYY-MM-DD): 2025-11-05
Enter Expiration Date (YYYY-MM-DD): 2025-11-12

--- Product Inventory Menu ---
1. Insert Product
2. Display Inventory (Inorder)
3. List Expired Products (Preorder)
0. Exit
Enter your choice: 2

Inventory Items (sorted by name):
Code: P102, Name: Bread, Price: 30, Quantity: 15, Received: 2025-11-05, Expiry: 2025-11-12
Code: P101, Name: Milk, Price: 50, Quantity: 20, Received: 2025-11-01, Expiry: 2025-11-10

--- Product Inventory Menu ---
1. Insert Product
2. Display Inventory (Inorder)
3. List Expired Products (Preorder)
0. Exit
Enter your choice: 3
Enter current date (YYYY-MM-DD) to check expired items: 2025-11-15

Expired Products:
Expired - Code: P101, Name: Milk, Expiry: 2025-11-10
Expired - Code: P102, Name: Bread, Expiry: 2025-11-12

--- Product Inventory Menu ---
1. Insert Product
2. Display Inventory (Inorder)
3. List Expired Products (Preorder)
0. Exit
Enter your choice: 0
Exiting...
