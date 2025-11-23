/*Write a C++ program to implement a Set using a Generalized Linked List (GLL).     For example:
 Let S = { p, q, {r, s, t, {}, {u, v}, w, x, {y, z}, a1, b1} }
 Store this structure using a Generalized Linked List and display the elements in correct set notation format.
*/

#include <iostream>
#include <string>
using namespace std;

struct GLLNode_TRP {
    bool isAtom_TRP;
    string data_TRP;
    GLLNode_TRP* sublist_TRP;
    GLLNode_TRP* next_TRP;
};

GLLNode_TRP* createAtom_TRP(const string& val_TRP) {
    GLLNode_TRP* node_TRP = new GLLNode_TRP;
    node_TRP->isAtom_TRP = true;
    node_TRP->data_TRP = val_TRP;
    node_TRP->sublist_TRP = nullptr;
    node_TRP->next_TRP = nullptr;
    return node_TRP;
}

GLLNode_TRP* createList_TRP(GLLNode_TRP* sublist_TRP) {
    GLLNode_TRP* node_TRP = new GLLNode_TRP;
    node_TRP->isAtom_TRP = false;
    node_TRP->sublist_TRP = sublist_TRP;
    node_TRP->next_TRP = nullptr;
    return node_TRP;
}

void display_TRP(GLLNode_TRP* node_TRP) {
    cout << "{";
    GLLNode_TRP* temp_TRP = node_TRP;
    while(temp_TRP) {
        if(temp_TRP->isAtom_TRP) {
            cout << temp_TRP->data_TRP;
        } else {
            display_TRP(temp_TRP->sublist_TRP);
        }
        if(temp_TRP->next_TRP) cout << ", ";
        temp_TRP = temp_TRP->next_TRP;
    }
    cout << "}";
}

int main() {
    // Construct inner sublists
    GLLNode_TRP* empty_TRP = nullptr;
    GLLNode_TRP* u_TRP = createAtom_TRP("u");
    GLLNode_TRP* v_TRP = createAtom_TRP("v");
    u_TRP->next_TRP = v_TRP;
    GLLNode_TRP* uvList_TRP = createList_TRP(u_TRP);

    GLLNode_TRP* r_TRP = createAtom_TRP("r");
    GLLNode_TRP* s_TRP = createAtom_TRP("s");
    GLLNode_TRP* t_TRP = createAtom_TRP("t");
    GLLNode_TRP* empty2_TRP = createList_TRP(nullptr);
    GLLNode_TRP* w_TRP = createAtom_TRP("w");
    GLLNode_TRP* x_TRP = createAtom_TRP("x");
    GLLNode_TRP* y_TRP = createAtom_TRP("y");
    GLLNode_TRP* z_TRP = createAtom_TRP("z");
    y_TRP->next_TRP = z_TRP;
    GLLNode_TRP* yzList_TRP = createList_TRP(y_TRP);
    GLLNode_TRP* a1_TRP = createAtom_TRP("a1");
    GLLNode_TRP* b1_TRP = createAtom_TRP("b1");

    // Connect inner list elements
    r_TRP->next_TRP = s_TRP;
    s_TRP->next_TRP = t_TRP;
    t_TRP->next_TRP = empty2_TRP;
    empty2_TRP->next_TRP = uvList_TRP;
    uvList_TRP->next_TRP = w_TRP;
    w_TRP->next_TRP = x_TRP;
    x_TRP->next_TRP = yzList_TRP;
    yzList_TRP->next_TRP = a1_TRP;
    a1_TRP->next_TRP = b1_TRP;

    GLLNode_TRP* innerList_TRP = createList_TRP(r_TRP);

    // Top-level list
    GLLNode_TRP* p_TRP = createAtom_TRP("p");
    GLLNode_TRP* q_TRP = createAtom_TRP("q");
    p_TRP->next_TRP = q_TRP;
    q_TRP->next_TRP = innerList_TRP;

    // Display the GLL as set
    cout << "GLL Set S = ";
    display_TRP(p_TRP);
    cout << endl;

    return 0;
}
