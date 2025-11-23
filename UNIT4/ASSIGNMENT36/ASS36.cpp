/*Write a program, using trees, to assign the roll nos. to the students of your class as per their previous years result. i.e topper will 
be roll no. 1*/

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
