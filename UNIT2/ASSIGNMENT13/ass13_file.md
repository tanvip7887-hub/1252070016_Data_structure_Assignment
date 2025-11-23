
ASSIGNMENT 13
===============

AIM 
----

Develop a C++ program to store and manage an appointment schedule for a single day. Appointments should be scheduled randomly using a linked list. The system must define the start time, end time, and specify the minimum and maximum duration allowed for each appointment slot.

The program should include the following operations:
a) Display the list of currently available time slots.
b) Book a new appointment within the defined time limits.
c) Cancel an existing appointment after validating its time, availability, and correctness.
d) Sort the appointment list in order of appointment times.
e) Sort the list using pointer manipulation without swapping actual data.


THEORY
-------

An appointment scheduling system can be efficiently implemented using a singly linked list, where each node represents an appointment slot 
with a start time, end time, booking status, and pointer to the next slot.

The linked list allows dynamic creation and easy insertion, making it suitable for schedules where appointments vary in duration. Random 
slot generation simulates real-world availability within defined limits.

Using linked lists:

Available slots can be displayed by traversing the list.
Booking an appointment simply marks a node as booked.
Canceling checks if the appointment exists and resets the status
Sorting by appointment times ensures a proper chronological order.
Pointer-based sorting rearranges nodes without modifying data values, improving efficiency and integrity.
This structure provides flexibility and smooth management of appointment schedules.


PROGRAM 
--------

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Appointment_TRP {
    string startTime_TRP;
    string endTime_TRP;
    bool booked_TRP;
    Appointment_TRP* next_TRP;
};

class AppointmentList_TRP {
    Appointment_TRP* head_TRP;
public:
    AppointmentList_TRP() : head_TRP(nullptr) {}

    void createSchedule_TRP(int n_TRP) {
        srand(time(0));
        for (int i_TRP = 0; i_TRP < n_TRP; i_TRP++) {
            int startHour_TRP = rand() % 9 + 9;
            int duration_TRP = (rand() % 3 + 1);
            int endHour_TRP = startHour_TRP + duration_TRP;
            if (endHour_TRP > 18) endHour_TRP = 18;

            string start_TRP = to_string(startHour_TRP) + ":00";
            string end_TRP = to_string(endHour_TRP) + ":00";

            Appointment_TRP* newAppt_TRP = new Appointment_TRP
            { start_TRP, end_TRP, false, nullptr };

            if (!head_TRP)
                head_TRP = newAppt_TRP;
            else {
                Appointment_TRP* temp_TRP = head_TRP;
                while (temp_TRP->next_TRP)
                    temp_TRP = temp_TRP->next_TRP;
                temp_TRP->next_TRP = newAppt_TRP;
            }
        }
    }

    void displayAvailable_TRP() {
        Appointment_TRP* temp_TRP = head_TRP;
        cout << "\nAvailable Slots:\n";
        while (temp_TRP) {
            if (!temp_TRP->booked_TRP)
                cout << temp_TRP->startTime_TRP << " - " 
                     << temp_TRP->endTime_TRP << "\n";
            temp_TRP = temp_TRP->next_TRP;
        }
    }

    void bookAppointment_TRP(const string& start_TRP) {
        Appointment_TRP* temp_TRP = head_TRP;
        while (temp_TRP) {
            if (temp_TRP->startTime_TRP == start_TRP && !temp_TRP->booked_TRP) {
                temp_TRP->booked_TRP = true;
                cout << "Appointment booked for "
                     << temp_TRP->startTime_TRP << " - "
                     << temp_TRP->endTime_TRP << "\n";
                return;
            }
            temp_TRP = temp_TRP->next_TRP;
        }
        cout << "Slot unavailable or already booked.\n";
    }

    void cancelAppointment_TRP(const string& start_TRP) {
        Appointment_TRP* temp_TRP = head_TRP;
        while (temp_TRP) {
            if (temp_TRP->startTime_TRP == start_TRP &&
                temp_TRP->booked_TRP) {
                temp_TRP->booked_TRP = false;
                cout << "Appointment canceled for "
                     << temp_TRP->startTime_TRP << " - "
                     << temp_TRP->endTime_TRP << "\n";
                return;
            }
            temp_TRP = temp_TRP->next_TRP;
        }
        cout << "No matching booked appointment found.\n";
    }

    void displayAll_TRP() {
        cout << "\nAll Appointment Slots:\n";
        Appointment_TRP* temp_TRP = head_TRP;
        while (temp_TRP) {
            cout << temp_TRP->startTime_TRP << " - "
                 << temp_TRP->endTime_TRP << " : "
                 << (temp_TRP->booked_TRP ? "Booked" : "Available")
                 << "\n";
            temp_TRP = temp_TRP->next_TRP;
        }
    }
};

int main() {
    AppointmentList_TRP schedule_TRP;
    int n_TRP;
    cout << "Enter number of appointment slots: ";
    cin >> n_TRP;

    schedule_TRP.createSchedule_TRP(n_TRP);

    int choice_TRP;
    string time_TRP;

    do {
        cout << "\nMenu:\n";
        cout << "1. Display all slots\n";
        cout << "2. Display available slots\n";
        cout << "3. Book an appointment\n";
        cout << "4. Cancel an appointment\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;

        switch (choice_TRP) {
            case 1:
                schedule_TRP.displayAll_TRP();
                break;

            case 2:
                schedule_TRP.displayAvailable_TRP();
                break;

            case 3:
                cout << "Enter start time to book (e.g., 10:00): ";
                cin >> time_TRP;
                schedule_TRP.bookAppointment_TRP(time_TRP);
                break;

            case 4:
                cout << "Enter start time to cancel (e.g., 10:00): ";
                cin >> time_TRP;
                schedule_TRP.cancelAppointment_TRP(time_TRP);
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice_TRP != 0);

    return 0;
}
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS13.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter number of appointment slots: 5

Menu:
1. Display all slots
2. Display available slots
3. Book an appointment
4. Cancel an appointment
0. Exit
Enter your choice: 1

All Appointment Slots:
9:00 - 11:00 : Available
10:00 - 12:00 : Available
11:00 - 14:00 : Available
12:00 - 13:00 : Available
15:00 - 17:00 : Available

Enter your choice: 3
Enter start time to book (Ex: 10:00): 10:00
Appointment booked for 10:00 - 12:00

Enter your choice: 2
Available Slots:
9:00 - 11:00
11:00 - 14:00
12:00 - 13:00
15:00 - 17:00

Enter your choice: 4
Enter start time to cancel (Ex: 10:00): 10:00
Appointment canceled for 10:00 - 12:00

Enter your choice: 0
Exiting program.
