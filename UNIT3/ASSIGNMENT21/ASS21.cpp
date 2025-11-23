/*WAP to build a simple stock price tracker that keeps a history of daily stock prices entered by the user. To allow users to go back and view or remove the most recent price, implement a stack using a linked list to store these integer prices.
Implement the following operations:
1.	record(price) – Add a new stock price (an integer) to the stack.
2.	remove() – Remove and return the most recent price (top of the stack).
3.	latest() – Return the most recent stock price without removing it.
4.	isEmpty() – Check if there are no prices recorded.
*/

#include <iostream>
using namespace std;

struct Node_TRP {
    int data_TRP;
    Node_TRP* next_TRP;
};

Node_TRP* top_TRP = nullptr;

Node_TRP* createNode_TRP(int data_TRP) {
    Node_TRP* newNode_TRP = new Node_TRP;
    newNode_TRP->data_TRP = data_TRP;
    newNode_TRP->next_TRP = nullptr;
    return newNode_TRP;
}

void record_TRP(int price_TRP) {
    Node_TRP* newNode_TRP = createNode_TRP(price_TRP);
    newNode_TRP->next_TRP = top_TRP;
    top_TRP = newNode_TRP;
}

int removePrice_TRP() {
    if (!top_TRP) {
        cout << "Stack is empty!\n";
        return -1;
    }
    Node_TRP* temp_TRP = top_TRP;
    int price_TRP = top_TRP->data_TRP;
    top_TRP = top_TRP->next_TRP;
    delete temp_TRP;
    return price_TRP;
}

int latest_TRP() {
    if (!top_TRP) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return top_TRP->data_TRP;
}

bool isEmpty_TRP() {
    return top_TRP == nullptr;
}

void display_TRP() {
    Node_TRP* temp_TRP = top_TRP;
    cout << "Stock prices (top to bottom): ";
    while (temp_TRP) {
        cout << temp_TRP->data_TRP << " ";
        temp_TRP = temp_TRP->next_TRP;
    }
    cout << endl;
}

int main() {
    int choice_TRP, price_TRP;
    do {
        cout << "\n--- Stock Price Tracker ---\n";
        cout << "1. Record price\n2. Remove most recent price\n3. Latest price\n4. Check if empty\n5. Display stack\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;
        switch(choice_TRP) {
            case 1:
                cout << "Enter price to record: ";
                cin >> price_TRP;
                record_TRP(price_TRP);
                break;
            case 2:
                price_TRP = removePrice_TRP();
                if (price_TRP != -1)
                    cout << "Removed price: " << price_TRP << endl;
                break;
            case 3:
                price_TRP = latest_TRP();
                if (price_TRP != -1)
                    cout << "Latest price: " << price_TRP << endl;
                break;
            case 4:
                if (isEmpty_TRP())
                    cout << "No prices recorded.\n";
                else
                    cout << "Prices are available.\n";
                break;
            case 5:
                display_TRP();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice_TRP != 0);

    return 0;
}
