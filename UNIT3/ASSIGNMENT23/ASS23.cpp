/*Write a program to implement multiple stack i.e more than two stack using array and perform following operations on it. A. Push B. Pop 
C. Stack Overflow D. Stack Underflow E. Display	*/

#include <iostream>
using namespace std;

class MultiStack_TRP {
    int* arr_TRP;
    int* top_TRP;
    int n_TRP, k_TRP;
    int* next_TRP;
    int freeTop_TRP;

public:
    MultiStack_TRP(int numStacks_TRP, int size_TRP) {
        k_TRP = numStacks_TRP;
        n_TRP = size_TRP;
        arr_TRP = new int[n_TRP];
        top_TRP = new int[k_TRP];
        next_TRP = new int[n_TRP];

        for (int i_TRP = 0; i_TRP < k_TRP; i_TRP++) top_TRP[i_TRP] = -1;
        for (int i_TRP = 0; i_TRP < n_TRP-1; i_TRP++) next_TRP[i_TRP] = i_TRP+1;
        next_TRP[n_TRP-1] = -1;
        freeTop_TRP = 0;
    }

    void push_TRP(int stackNum_TRP, int value_TRP) {
        if (freeTop_TRP == -1) {
            cout << "Stack Overflow\n";
            return;
        }
        int i_TRP = freeTop_TRP;
        freeTop_TRP = next_TRP[i_TRP];
        arr_TRP[i_TRP] = value_TRP;
        next_TRP[i_TRP] = top_TRP[stackNum_TRP];
        top_TRP[stackNum_TRP] = i_TRP;
        cout << "Pushed " << value_TRP << " into stack " << stackNum_TRP+1 << endl;
    }

    void pop_TRP(int stackNum_TRP) {
        if (top_TRP[stackNum_TRP] == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        int i_TRP = top_TRP[stackNum_TRP];
        top_TRP[stackNum_TRP] = next_TRP[i_TRP];
        next_TRP[i_TRP] = freeTop_TRP;
        freeTop_TRP = i_TRP;
        cout << "Popped " << arr_TRP[i_TRP] << " from stack " << stackNum_TRP+1 << endl;
    }

    void display_TRP(int stackNum_TRP) {
        if (top_TRP[stackNum_TRP] == -1) {
            cout << "Stack " << stackNum_TRP+1 << " is empty\n";
            return;
        }
        int i_TRP = top_TRP[stackNum_TRP];
        cout << "Stack " << stackNum_TRP+1 << ": ";
        while (i_TRP != -1) {
            cout << arr_TRP[i_TRP] << " ";
            i_TRP = next_TRP[i_TRP];
        }
        cout << endl;
    }
};

int main() {
    int numStacks_TRP, size_TRP, choice_TRP, stackNum_TRP, value_TRP;
    cout << "Enter number of stacks: ";
    cin >> numStacks_TRP;
    cout << "Enter total array size: ";
    cin >> size_TRP;

    MultiStack_TRP ms_TRP(numStacks_TRP, size_TRP);

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_TRP;
        switch(choice_TRP) {
            case 1:
                cout << "Enter stack number (1 to " << numStacks_TRP << "): ";
                cin >> stackNum_TRP;
                cout << "Enter value to push: ";
                cin >> value_TRP;
                ms_TRP.push_TRP(stackNum_TRP-1, value_TRP);
                break;
            case 2:
                cout << "Enter stack number (1 to " << numStacks_TRP << "): ";
                cin >> stackNum_TRP;
                ms_TRP.pop_TRP(stackNum_TRP-1);
                break;
            case 3:
                for(int i_TRP=0; i_TRP<numStacks_TRP; i_TRP++)
                    ms_TRP.display_TRP(i_TRP);
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
