
ASSIGNMENT 18
==============

AIM - Implement Bubble sort using Doubly Linked List	

THEORY
-------

Bubble Sort is a simple comparison-based sorting method where adjacent nodes are compared and swapped if they are in the wrong order.
When implemented using a doubly linked list, movement in both forward and backward directions becomes easy.
Each pass pushes the largest element towards the end of the list, just like bubbles rise to the top.
Swapping only requires updating pointers, not shifting data like arrays.
This method is easy to implement and works well for linked structures.


PROGRAM
--------

```CPP
#include <iostream>
using namespace std;

struct Node_TRP {
    int coeff_TRP;
    int power_TRP;
    Node_TRP* next_TRP;
};

Node_TRP* createNode_TRP(int coeff_TRP, int power_TRP) {
    Node_TRP* newNode_TRP = new Node_TRP;
    newNode_TRP->coeff_TRP = coeff_TRP;
    newNode_TRP->power_TRP = power_TRP;
    newNode_TRP->next_TRP = nullptr;
    return newNode_TRP;
}

void insertTerm_TRP(Node_TRP*& poly_TRP, int coeff_TRP, int power_TRP) {
    Node_TRP* newNode_TRP = createNode_TRP(coeff_TRP, power_TRP);
    if (!poly_TRP)
        poly_TRP = newNode_TRP;
    else {
        Node_TRP* temp_TRP = poly_TRP;
        while (temp_TRP->next_TRP)
            temp_TRP = temp_TRP->next_TRP;
        temp_TRP->next_TRP = newNode_TRP;
    }
}

void display_TRP(Node_TRP* poly_TRP) {
    while (poly_TRP) {
        cout << poly_TRP->coeff_TRP << "x^" << poly_TRP->power_TRP;
        if (poly_TRP->next_TRP)
            cout << " + ";
        poly_TRP = poly_TRP->next_TRP;
    }
    cout << endl;
}

Node_TRP* addPolynomials_TRP(Node_TRP* poly1_TRP, Node_TRP* poly2_TRP) {
    Node_TRP* result_TRP = nullptr;
    while (poly1_TRP && poly2_TRP) {
        if (poly1_TRP->power_TRP > poly2_TRP->power_TRP) {
            insertTerm_TRP(result_TRP, poly1_TRP->coeff_TRP, poly1_TRP->power_TRP);
            poly1_TRP = poly1_TRP->next_TRP;
        }
        else if (poly1_TRP->power_TRP < poly2_TRP->power_TRP) {
            insertTerm_TRP(result_TRP, poly2_TRP->coeff_TRP, poly2_TRP->power_TRP);
            poly2_TRP = poly2_TRP->next_TRP;
        }
        else {
            insertTerm_TRP(result_TRP, poly1_TRP->coeff_TRP + poly2_TRP->coeff_TRP, poly1_TRP->power_TRP);
            poly1_TRP = poly1_TRP->next_TRP;
            poly2_TRP = poly2_TRP->next_TRP;
        }
    }
    while (poly1_TRP) {
        insertTerm_TRP(result_TRP, poly1_TRP->coeff_TRP, poly1_TRP->power_TRP);
        poly1_TRP = poly1_TRP->next_TRP;
    }
    while (poly2_TRP) {
        insertTerm_TRP(result_TRP, poly2_TRP->coeff_TRP, poly2_TRP->power_TRP);
        poly2_TRP = poly2_TRP->next_TRP;
    }
    return result_TRP;
}

int main() {
    Node_TRP *poly1_TRP = nullptr, *poly2_TRP = nullptr, *sum_TRP = nullptr;

    insertTerm_TRP(poly1_TRP, 3, 3);
    insertTerm_TRP(poly1_TRP, 2, 2);
    insertTerm_TRP(poly1_TRP, 5, 1);

    insertTerm_TRP(poly2_TRP, 6, 3);
    insertTerm_TRP(poly2_TRP, 4, 2);
    insertTerm_TRP(poly2_TRP, 2, 0);

    cout << "First Polynomial: ";
    display_TRP(poly1_TRP);

    cout << "Second Polynomial: ";
    display_TRP(poly2_TRP);

    sum_TRP = addPolynomials_TRP(poly1_TRP, poly2_TRP);

    cout << "Resultant Polynomial after Addition: ";
    display_TRP(sum_TRP);

    return 0;
}
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS18.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

First Polynomial: 3x^3 + 2x^2 + 5x^1
Second Polynomial: 6x^3 + 4x^2 + 2x^0
Resultant Polynomial after Addition: 9x^3 + 6x^2 + 5x^1 + 2x^0
