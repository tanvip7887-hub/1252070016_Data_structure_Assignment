/*Write a program that maintains a queue of passengers waiting to see a ticket agent. The program user should be able to insert a new 
passenger at the rear of the queue, Display the passenger at the front of the Queue, or remove the passenger at the front of the queue. 
The program will display the number of passengers left in the queue just before it terminates.*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> passengers_TRP;
    int choice_TRP;
    string name_TRP;

    do {
        cout << "\n--- Passenger Queue Menu ---\n";
        cout << "1. Add passenger\n2. Display front passenger\n3. Remove front passenger\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;

        switch(choice_TRP) {
            case 1:
                cout << "Enter passenger name: ";
                cin >> ws;
                getline(cin, name_TRP);
                passengers_TRP.push(name_TRP);
                cout << name_TRP << " added to the queue.\n";
                break;
            case 2:
                if(passengers_TRP.empty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Front passenger: " << passengers_TRP.front() << endl;
                break;
            case 3:
                if(passengers_TRP.empty())
                    cout << "Queue is empty.\n";
                else {
                    cout << passengers_TRP.front() << " removed from the queue.\n";
                    passengers_TRP.pop();
                }
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice_TRP != 0);

    cout << "Number of passengers left in the queue: " << passengers_TRP.size() << endl;

    return 0;
}
