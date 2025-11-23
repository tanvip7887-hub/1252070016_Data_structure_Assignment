/*
 Develop a C++ program to store and manage an appointment schedule for a single day. Appointments should be scheduled randomly using a 
 linked list. The system must define the start time, end time, and specify the minimum and maximum duration allowed for each appointment slot.
 The program should include the following operations:
 a) Display the list of currently available time slots.
 b) Book a new appointment within the defined time limits.
 c) Cancel an existing appointment after validating its time, availability, and correctness.
 d) Sort the appointment list in order of appointment times.
 e) Sort the list based on appointment times using pointer manipulation (without swapping data values).
*/

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
            int startHour_TRP = rand() % 9 + 9; // Random start between 9 AM - 5 PM
            int duration_TRP = (rand() % 3 + 1); // 1-3 hours
            int endHour_TRP = startHour_TRP + duration_TRP;
            if (endHour_TRP > 18) endHour_TRP = 18;

            string start_TRP = to_string(startHour_TRP) + ":00";
            string end_TRP = to_string(endHour_TRP) + ":00";

            Appointment_TRP* newAppt_TRP = new Appointment_TRP{start_TRP, end_TRP, false, nullptr};
            if (!head_TRP) head_TRP = newAppt_TRP;
            else {
                Appointment_TRP* temp_TRP = head_TRP;
                while (temp_TRP->next_TRP) temp_TRP = temp_TRP->next_TRP;
                temp_TRP->next_TRP = newAppt_TRP;
            }
        }
    }

    void displayAvailable_TRP() {
        Appointment_TRP* temp_TRP = head_TRP;
        cout << "\nAvailable Slots:\n";
        while (temp_TRP) {
            if (!temp_TRP->booked_TRP)
                cout << temp_TRP->startTime_TRP << " - " << temp_TRP->endTime_TRP << "\n";
            temp_TRP = temp_TRP->next_TRP;
        }
    }

    void bookAppointment_TRP(const string& start_TRP) {
        Appointment_TRP* temp_TRP = head_TRP;
        while (temp_TRP) {
            if (temp_TRP->startTime_TRP == start_TRP && !temp_TRP->booked_TRP) {
                temp_TRP->booked_TRP = true;
                cout << "Appointment booked for " << temp_TRP->startTime_TRP << " - " << temp_TRP->endTime_TRP << "\n";
                return;
            }
            temp_TRP = temp_TRP->next_TRP;
        }
        cout << "Slot unavailable or already booked.\n";
    }

    void cancelAppointment_TRP(const string& start_TRP) {
        Appointment_TRP* temp_TRP = head_TRP;
        while (temp_TRP) {
            if (temp_TRP->startTime_TRP == start_TRP && temp_TRP->booked_TRP) {
                temp_TRP->booked_TRP = false;
                cout << "Appointment canceled for " << temp_TRP->startTime_TRP << " - " << temp_TRP->endTime_TRP << "\n";
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
            cout << temp_TRP->startTime_TRP << " - " << temp_TRP->endTime_TRP << " : "
                 << (temp_TRP->booked_TRP ? "Booked" : "Available") << "\n";
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

        switch(choice_TRP) {
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
