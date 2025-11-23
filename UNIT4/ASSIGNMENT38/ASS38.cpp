/*Write a program to efficiently search a particular employee record by using Tree data structure. Also sort the data on emp­id in ascending order.*/

#include <iostream>
#include <string>
using namespace std;

struct Employee_TRP {
    int empId_TRP;
    string name_TRP;
    string dept_TRP;
    Employee_TRP* left_TRP;
    Employee_TRP* right_TRP;
};

Employee_TRP* createNode_TRP(int empId_TRP, string name_TRP, string dept_TRP) {
    Employee_TRP* newNode_TRP = new Employee_TRP;
    newNode_TRP->empId_TRP = empId_TRP;
    newNode_TRP->name_TRP = name_TRP;
    newNode_TRP->dept_TRP = dept_TRP;
    newNode_TRP->left_TRP = newNode_TRP->right_TRP = nullptr;
    return newNode_TRP;
}

Employee_TRP* insert_TRP(Employee_TRP* root_TRP, int empId_TRP, string name_TRP, string dept_TRP) {
    if(!root_TRP) return createNode_TRP(empId_TRP, name_TRP, dept_TRP);
    if(empId_TRP < root_TRP->empId_TRP)
        root_TRP->left_TRP = insert_TRP(root_TRP->left_TRP, empId_TRP, name_TRP, dept_TRP);
    else if(empId_TRP > root_TRP->empId_TRP)
        root_TRP->right_TRP = insert_TRP(root_TRP->right_TRP, empId_TRP, name_TRP, dept_TRP);
    return root_TRP;
}

Employee_TRP* search_TRP(Employee_TRP* root_TRP, int empId_TRP) {
    if(!root_TRP || root_TRP->empId_TRP == empId_TRP) return root_TRP;
    if(empId_TRP < root_TRP->empId_TRP) return search_TRP(root_TRP->left_TRP, empId_TRP);
    return search_TRP(root_TRP->right_TRP, empId_TRP);
}

void inorder_TRP(Employee_TRP* root_TRP) {
    if(!root_TRP) return;
    inorder_TRP(root_TRP->left_TRP);
    cout << "EmpID: " << root_TRP->empId_TRP 
         << ", Name: " << root_TRP->name_TRP 
         << ", Dept: " << root_TRP->dept_TRP << endl;
    inorder_TRP(root_TRP->right_TRP);
}

int main() {
    Employee_TRP* root_TRP = nullptr;
    int choice_TRP, empId_TRP;
    string name_TRP, dept_TRP;

    do {
        cout << "\n--- Employee BST Menu ---\n";
        cout << "1. Add Employee\n2. Search Employee by ID\n3. Display Employees (Sorted by ID)\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;

        switch(choice_TRP) {
            case 1:
                cout << "Enter Employee ID: "; cin >> empId_TRP;
                cout << "Enter Name: "; cin >> ws; getline(cin, name_TRP);
                cout << "Enter Department: "; getline(cin, dept_TRP);
                root_TRP = insert_TRP(root_TRP, empId_TRP, name_TRP, dept_TRP);
                break;

            case 2:
                cout << "Enter Employee ID to search: "; cin >> empId_TRP;
                {
                    Employee_TRP* emp_TRP = search_TRP(root_TRP, empId_TRP);
                    if(emp_TRP)
                        cout << "Found - EmpID: " << emp_TRP->empId_TRP 
                             << ", Name: " << emp_TRP->name_TRP 
                             << ", Dept: " << emp_TRP->dept_TRP << endl;
                    else
                        cout << "Employee not found.\n";
                }
                break;

            case 3:
                cout << "Employees sorted by ID:\n";
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
