/*Write a Program to create a Binary Tree and perform following Nonrecursive operations on it. a. Inorder Traversal b. Preorder Traversal 
c. Display Number of Leaf Nodes d. Mirror Image*/

#include <iostream>
#include <stack>
#include <queue>
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
    queue<Node_TRP*> q_TRP;
    q_TRP.push(root_TRP);
    while(!q_TRP.empty()) {
        Node_TRP* temp_TRP = q_TRP.front();
        q_TRP.pop();
        if(!temp_TRP->left_TRP) { temp_TRP->left_TRP = createNode_TRP(data_TRP); break; }
        else q_TRP.push(temp_TRP->left_TRP);
        if(!temp_TRP->right_TRP) { temp_TRP->right_TRP = createNode_TRP(data_TRP); break; }
        else q_TRP.push(temp_TRP->right_TRP);
    }
    return root_TRP;
}

void inorder_TRP(Node_TRP* root_TRP) {
    stack<Node_TRP*> s_TRP;
    Node_TRP* curr_TRP = root_TRP;
    cout << "Inorder: ";
    while(curr_TRP || !s_TRP.empty()) {
        while(curr_TRP) { s_TRP.push(curr_TRP); curr_TRP = curr_TRP->left_TRP; }
        curr_TRP = s_TRP.top(); s_TRP.pop();
        cout << curr_TRP->data_TRP << " ";
        curr_TRP = curr_TRP->right_TRP;
    }
    cout << endl;
}

void preorder_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return;
    stack<Node_TRP*> s_TRP;
    s_TRP.push(root_TRP);
    cout << "Preorder: ";
    while(!s_TRP.empty()) {
        Node_TRP* temp_TRP = s_TRP.top(); s_TRP.pop();
        cout << temp_TRP->data_TRP << " ";
        if(temp_TRP->right_TRP) s_TRP.push(temp_TRP->right_TRP);
        if(temp_TRP->left_TRP) s_TRP.push(temp_TRP->left_TRP);
    }
    cout << endl;
}

int countLeafNodes_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return 0;
    int count_TRP = 0;
    stack<Node_TRP*> s_TRP;
    s_TRP.push(root_TRP);
    while(!s_TRP.empty()) {
        Node_TRP* temp_TRP = s_TRP.top(); s_TRP.pop();
        if(!temp_TRP->left_TRP && !temp_TRP->right_TRP) count_TRP++;
        if(temp_TRP->right_TRP) s_TRP.push(temp_TRP->right_TRP);
        if(temp_TRP->left_TRP) s_TRP.push(temp_TRP->left_TRP);
    }
    return count_TRP;
}

void mirror_TRP(Node_TRP* root_TRP) {
    if(!root_TRP) return;
    stack<Node_TRP*> s_TRP;
    s_TRP.push(root_TRP);
    while(!s_TRP.empty()) {
        Node_TRP* temp_TRP = s_TRP.top(); s_TRP.pop();
        swap(temp_TRP->left_TRP, temp_TRP->right_TRP);
        if(temp_TRP->left_TRP) s_TRP.push(temp_TRP->left_TRP);
        if(temp_TRP->right_TRP) s_TRP.push(temp_TRP->right_TRP);
    }
    cout << "Mirror image created.\n";
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
                inorder_TRP(root_TRP);
                break;
            case 3:
                preorder_TRP(root_TRP);
                break;
            case 4:
                cout << "Number of leaf nodes: " << countLeafNodes_TRP(root_TRP) << endl;
                break;
            case 5:
                mirror_TRP(root_TRP);
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
