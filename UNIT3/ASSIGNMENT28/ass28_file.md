
ASSIGNMENT 28
==============

AIM
----

Write a program that maintains a queue of passengers waiting to see a ticket agent. The program user should be able to insert a new passenger at the rear of the queue, Display the passenger at the front of the Queue, or remove the passenger at the front of the queue. 
The program will display the number of passengers left in the queue just before it terminates.

THEORY
-------

A queue is a linear data structure that follows the FIFO (First-In, First-Out) principle.
The passenger who enters first will be served first.
The queue uses two main operations:

Enqueue to add a passenger at the rear.
Dequeue to remove a passenger from the front.
The front element always represents the next passenger to be served.
In this program, the queue stores passenger names and allows adding, displaying, and removing passengers.
Before terminating, the program displays the total number of passengers still waiting in the queue.


PROGRAM
--------

```CPP
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
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS28.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- Passenger Queue Menu ---
1. Add passenger
2. Display front passenger
3. Remove front passenger
0. Exit
Enter your choice: 1
Enter passenger name: Rahul
Rahul added to the queue.

Enter your choice: 1
Enter passenger name: Sneha
Sneha added to the queue.

Enter your choice: 2
Front passenger: Rahul

Enter your choice: 3
Rahul removed from the queue.

Enter your choice: 2
Front passenger: Sneha

Enter your choice: 1
Enter passenger name: Arjun
Arjun added to the queue.

Enter your choice: 3
Sneha removed from the queue.

Enter your choice: 0
Exiting...

Number of passengers left in the queue: 1
