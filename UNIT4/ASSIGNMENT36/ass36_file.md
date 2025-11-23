
ASSIGNMENT 36
==============

AIM
----
Write a program, using trees, to assign the roll nos. to the students of your class as per their previous years result. i.e topper will 
be roll no. 1


THEORY
-------

A Binary Search Tree (BST) can be used to arrange students according to their marks in a structured way.
Each node stores the student’s name and marks, and children are arranged based on comparison of marks.
Students with higher marks are inserted to the left, so the topper naturally reaches the first position during traversal.
An inorder traversal of this BST gives the students in descending order of marks.
Roll numbers are assigned during traversal, ensuring the topper gets Roll No. 1 automatically.
This method is efficient because tree-based ordering avoids sorting separately and arranges data dynamically.


PROGRAM
--------

```CPP
#include <iostream>
#include <vector>
using namespace std;

struct Node_TRP {
    string name_TRP;
    int marks_TRP;
    Node_TRP* left_TRP;
    Node_TRP* right_TRP;
};

Node_TRP* createNode_TRP(string name_TRP, int marks_TRP) {
    Node_TRP* newNode_TRP = new Node_TRP;
    newNode_TRP->name_TRP = name_TRP;
    newNode_TRP->marks_TRP = marks_TRP;
    newNode_TRP->left_TRP = newNode_TRP->right_TRP = nullptr;
    return newNode_TRP;
}

Node_TRP* insert_TRP(Node_TRP* root_TRP, string name_TRP, int marks_TRP) {
    if(!root_TRP) return createNode_TRP(name_TRP, marks_TRP);
    if(marks_TRP > root_TRP->marks_TRP)
        root_TRP->left_TRP = insert_TRP(root_TRP->left_TRP, name_TRP, marks_TRP);
    else
        root_TRP->right_TRP = insert_TRP(root_TRP->right_TRP, name_TRP, marks_TRP);
    return root_TRP;
}

void assignRollNo_TRP(Node_TRP* root_TRP, int &rollNo_TRP, vector<pair<int,string>> &result_TRP) {
    if(!root_TRP) return;
    assignRollNo_TRP(root_TRP->left_TRP, rollNo_TRP, result_TRP);
    result_TRP.push_back({rollNo_TRP++, root_TRP->name_TRP});
    assignRollNo_TRP(root_TRP->right_TRP, rollNo_TRP, result_TRP);
}

int main() {
    Node_TRP* root_TRP = nullptr;
    int n_TRP, marks_TRP;
    string name_TRP;
    
    cout << "Enter number of students: ";
    cin >> n_TRP;
    
    for(int i_TRP=0; i_TRP<n_TRP; i_TRP++) {
        cout << "Enter name of student: ";
        cin >> ws;
        getline(cin, name_TRP);
        cout << "Enter marks: ";
        cin >> marks_TRP;
        root_TRP = insert_TRP(root_TRP, name_TRP, marks_TRP);
    }

    int rollNo_TRP = 1;
    vector<pair<int,string>> rollList_TRP;
    assignRollNo_TRP(root_TRP, rollNo_TRP, rollList_TRP);

    cout << "\nRoll Numbers Assigned (Topper gets Roll No. 1):\n";
    for(auto &p_TRP : rollList_TRP) {
        cout << "Roll No. " << p_TRP.first << " : " << p_TRP.second << endl;
    }

    return 0;
}
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS36.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter number of students: 4
Enter name of student: Riya
Enter marks: 92
Enter name of student: Tanvi
Enter marks: 85
Enter name of student: Akash
Enter marks: 78
Enter name of student: Meera
Enter marks: 95

Roll Numbers Assigned (Topper gets Roll No. 1):
Roll No. 1 : Meera
Roll No. 2 : Riya
Roll No. 3 : Tanvi
Roll No. 4 : Akash
