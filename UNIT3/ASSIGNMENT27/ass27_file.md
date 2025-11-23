
ASSIGNMENT 27
==============

AIM
----

Pizza parlour accepting maximum n orders. Orders are served on an FCFS basis. Order once placed can’t be cancelled. Write C++ program to 
simulate the system using circular QUEUE.	

THEORY
-------

A circular queue is a linear data structure in which the last position is connected back to the first position, forming a circle.
It allows efficient use of memory because no space is wasted when elements are removed.
In a pizza parlour system, customer orders are accepted on a First-Come, First-Served (FCFS) basis.
Once an order is placed, it cannot be cancelled, so the circular queue ensures proper order management.
The front pointer indicates the order to be served next, while the rear pointer marks the latest placed order.
When the queue becomes full, no more orders can be taken, and when it becomes empty, there are no pending orders to serve.


PROGRAM
---------

```CPP
#include <iostream>
using namespace std;

class CircularQueue_TRP {
    int* arr_TRP;
    int front_TRP, rear_TRP, size_TRP, capacity_TRP;
public:
    CircularQueue_TRP(int n_TRP) {
        capacity_TRP = n_TRP;
        arr_TRP = new int[capacity_TRP];
        front_TRP = rear_TRP = -1;
        size_TRP = 0;
    }

    bool isFull_TRP() {
        return size_TRP == capacity_TRP;
    }

    bool isEmpty_TRP() {
        return size_TRP == 0;
    }

    void enqueue_TRP(int order_TRP) {
        if (isFull_TRP()) {
            cout << "Queue is full! Cannot accept more orders.\n";
            return;
        }
        if (isEmpty_TRP()) front_TRP = rear_TRP = 0;
        else rear_TRP = (rear_TRP + 1) % capacity_TRP;
        arr_TRP[rear_TRP] = order_TRP;
        size_TRP++;
        cout << "Order " << order_TRP << " placed.\n";
    }

    void dequeue_TRP() {
        if (isEmpty_TRP()) {
            cout << "No orders to serve.\n";
            return;
        }
        cout << "Order " << arr_TRP[front_TRP] << " served.\n";
        if (front_TRP == rear_TRP) front_TRP = rear_TRP = -1;
        else front_TRP = (front_TRP + 1) % capacity_TRP;
        size_TRP--;
    }

    void display_TRP() {
        if (isEmpty_TRP()) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Pending orders: ";
        int i_TRP = front_TRP;
        for(int cnt_TRP = 0; cnt_TRP < size_TRP; cnt_TRP++) {
            cout << arr_TRP[i_TRP] << " ";
            i_TRP = (i_TRP + 1) % capacity_TRP;
        }
        cout << endl;
    }
};

int main() {
    int n_TRP, choice_TRP, order_TRP;
    cout << "Enter maximum number of orders: ";
    cin >> n_TRP;
    CircularQueue_TRP pq_TRP(n_TRP);

    do {
        cout << "\n--- Pizza Parlour Menu ---\n";
        cout << "1. Place Order\n2. Serve Order\n3. Display Orders\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_TRP;
        switch(choice_TRP) {
            case 1:
                cout << "Enter order number: ";
                cin >> order_TRP;
                pq_TRP.enqueue_TRP(order_TRP);
                break;
            case 2:
                pq_TRP.dequeue_TRP();
                break;
            case 3:
                pq_TRP.display_TRP();
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

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS27.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter maximum number of orders: 5

--- Pizza Parlour Menu ---
1. Place Order
2. Serve Order
3. Display Orders
0. Exit
Enter choice: 1
Enter order number: 101
Order 101 placed.

Enter choice: 1
Enter order number: 102
Order 102 placed.

Enter choice: 1
Enter order number: 103
Order 103 placed.

Enter choice: 3
Pending orders: 101 102 103

Enter choice: 2
Order 101 served.

Enter choice: 3
Pending orders: 102 103

Enter choice: 1
Enter order number: 104
Order 104 placed.

Enter choice: 1
Enter order number: 105
Order 105 placed.

Enter choice: 1
Enter order number: 106
Queue is full! Cannot accept more orders.

Enter choice: 2
Order 102 served.

Enter choice: 3
Pending orders: 103 104 105

Enter choice: 0
Exiting...
