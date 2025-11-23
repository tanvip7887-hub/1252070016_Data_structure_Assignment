/*WAP to perform addition o f two polynomials using singly linked list.*/

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
