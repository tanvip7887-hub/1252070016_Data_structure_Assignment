
ASSIGNMENT 17
==============

AIM - WAP to perform addition o f two polynomials using singly linked list.

THEORY
-------

Polynomial addition can be done easily using a singly linked list because each term of a polynomial can be stored as a separate node. Every 
node contains the coefficient, power, and a pointer to the next term. The terms of both polynomials are compared by their powers, and equal 
powers are added together. If one polynomial has extra terms, they are directly copied to the result. This method makes polynomial operations simple, structured, and memory-efficient.


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
    if (!poly_TRP) {
        cout << "Polynomial is empty\n";
        return;
    }
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
    int choice_TRP, coeff_TRP, power_TRP;

    do {
        cout << "\n--- Polynomial Operations ---\n";
        cout << "1. Insert term in 1st polynomial\n";
        cout << "2. Insert term in 2nd polynomial\n";
        cout << "3. Display 1st polynomial\n";
        cout << "4. Display 2nd polynomial\n";
        cout << "5. Add polynomials\n";
        cout << "6. Display resultant polynomial\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_TRP;

        switch(choice_TRP) {
            case 1:
                cout << "Enter coefficient and power: ";
                cin >> coeff_TRP >> power_TRP;
                insertTerm_TRP(poly1_TRP, coeff_TRP, power_TRP);
                break;
            case 2:
                cout << "Enter coefficient and power: ";
                cin >> coeff_TRP >> power_TRP;
                insertTerm_TRP(poly2_TRP, coeff_TRP, power_TRP);
                break;
            case 3:
                cout << "First Polynomial: ";
                display_TRP(poly1_TRP);
                break;
            case 4:
                cout << "Second Polynomial: ";
                display_TRP(poly2_TRP);
                break;
            case 5:
                sum_TRP = addPolynomials_TRP(poly1_TRP, poly2_TRP);
                cout << "Polynomials added.\n";
                break;
            case 6:
                cout << "Resultant Polynomial: ";
                display_TRP(sum_TRP);
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

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS17.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- Polynomial Operations ---
1. Insert term in 1st polynomial
2. Insert term in 2nd polynomial
3. Display 1st polynomial
4. Display 2nd polynomial
5. Add polynomials
6. Display resultant polynomial
0. Exit
Enter choice: 1
Enter coefficient and power: 5 2

Enter choice: 1
Enter coefficient and power: 4 1

Enter choice: 2
Enter coefficient and power: 3 2

Enter choice: 2
Enter coefficient and power: 2 0

Enter choice: 3
First Polynomial: 5x^2 + 4x^1

Enter choice: 4
Second Polynomial: 3x^2 + 2x^0

Enter choice: 5
Polynomials added.

Enter choice: 6
Resultant Polynomial: 8x^2 + 4x^1 + 2x^0

Enter choice: 0
Exiting...
