/*Write a program to implement deletion operations in the product inventory system using a search tree.
 Each product must store the following information:
    ●	Unique Product Code
    ●	Product Name
    ●	Price
    ●	Quantity in Stock
    ●	Date Received
    ●	Expiration Date
Implement the following operations:
1.	Delete a product using its unique product code.
2.	Delete all expired products based on the current date.	
*/

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

Product_TRP* findMin_TRP(Product_TRP* root_TRP) {
    while(root_TRP && root_TRP->left_TRP) root_TRP = root_TRP->left_TRP;
    return root_TRP;
}

Product_TRP* deleteByCode_TRP(Product_TRP* root_TRP, string code_TRP) {
    if(!root_TRP) return nullptr;
    if(code_TRP < root_TRP->code_TRP)
        root_TRP->left_TRP = deleteByCode_TRP(root_TRP->left_TRP, code_TRP);
    else if(code_TRP > root_TRP->code_TRP)
        root_TRP->right_TRP = deleteByCode_TRP(root_TRP->right_TRP, code_TRP);
    else {
        if(!root_TRP->left_TRP) { Product_TRP* temp_TRP = root_TRP->right_TRP; delete root_TRP; return temp_TRP; }
        else if(!root_TRP->right_TRP) { Product_TRP* temp_TRP = root_TRP->left_TRP; delete root_TRP; return temp_TRP; }
        else {
            Product_TRP* temp_TRP = findMin_TRP(root_TRP->right_TRP);
            root_TRP->code_TRP = temp_TRP->code_TRP;
            root_TRP->name_TRP = temp_TRP->name_TRP;
            root_TRP->price_TRP = temp_TRP->price_TRP;
            root_TRP->quantity_TRP = temp_TRP->quantity_TRP;
            root_TRP->dateReceived_TRP = temp_TRP->dateReceived_TRP;
            root_TRP->expiryDate_TRP = temp_TRP->expiryDate_TRP;
            root_TRP->right_TRP = deleteByCode_TRP(root_TRP->right_TRP, temp_TRP->code_TRP);
        }
    }
    return root_TRP;
}

Product_TRP* deleteExpired_TRP(Product_TRP* root_TRP, string currentDate_TRP) {
    if(!root_TRP) return nullptr;
    root_TRP->left_TRP = deleteExpired_TRP(root_TRP->left_TRP, currentDate_TRP);
    root_TRP->right_TRP = deleteExpired_TRP(root_TRP->right_TRP, currentDate_TRP);
    if(root_TRP->expiryDate_TRP < currentDate_TRP) {
        root_TRP = deleteByCode_TRP(root_TRP, root_TRP->code_TRP);
    }
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

int main() {
    Product_TRP* root_TRP = nullptr;
    int choice_TRP, quantity_TRP;
    double price_TRP;
    string code_TRP, name_TRP, dateReceived_TRP, expiryDate_TRP, currentDate_TRP;

    do {
        cout << "\n--- Product Inventory Deletion Menu ---\n";
        cout << "1. Insert Product\n2. Delete Product by Code\n3. Delete Expired Products\n4. Display Inventory\n0. Exit\n";
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
                cout << "Enter Product Code to delete: "; cin >> code_TRP;
                root_TRP = deleteByCode_TRP(root_TRP, code_TRP);
                cout << "Product deleted if it existed.\n";
                break;
            case 3:
                cout << "Enter current date (YYYY-MM-DD): "; cin >> currentDate_TRP;
                root_TRP = deleteExpired_TRP(root_TRP, currentDate_TRP);
                cout << "Expired products deleted.\n";
                break;
            case 4:
                cout << "Current Inventory:\n";
                inorder_TRP(root_TRP);
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
