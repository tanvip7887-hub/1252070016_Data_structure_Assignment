
ASSIGNMENT 26
==============

AIM
----

write a program to keep track of patients as they checked into a medical clinic, assigning patients to doctors on a first-come, first-served basis.

THEORY
-------

This program uses a queue to manage patients in a clinic. A queue follows the FIFO (First-In, First-Out) rule, meaning the patient who comes first will be seen by the doctor first.
Each patient is added to the queue when they check in. When a doctor becomes available, the program removes the patient from the front of the queue and assigns them to the doctor.
This ensures fair and orderly service without skipping anyone. The queue also helps display all waiting patients in the order they arrived.

PROGRAM
--------

```CPP
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient_TRP {
    string name_TRP;
    string doctor_TRP;
};

int main() {
    queue<Patient_TRP> clinicQueue_TRP;
    int choice_TRP;
    string name_TRP, doctor_TRP;

    do {
        cout << "\n--- Clinic Menu ---\n";
        cout << "1. Check-in patient\n2. Assign next patient to doctor\n3. Display waiting patients\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_TRP;

        switch(choice_TRP) {
            case 1:
                cout << "Enter patient name: ";
                cin >> ws;
                getline(cin, name_TRP);
                clinicQueue_TRP.push({name_TRP, ""});
                cout << name_TRP << " has checked in.\n";
                break;
            case 2:
                if(clinicQueue_TRP.empty()) {
                    cout << "No patients waiting.\n";
                } else {
                    cout << "Enter doctor's name: ";
                    cin >> ws;
                    getline(cin, doctor_TRP);
                    Patient_TRP p_TRP = clinicQueue_TRP.front();
                    clinicQueue_TRP.pop();
                    p_TRP.doctor_TRP = doctor_TRP;
                    cout << "Patient " << p_TRP.name_TRP << " assigned to Dr. " << p_TRP.doctor_TRP << endl;
                }
                break;
            case 3:
                if(clinicQueue_TRP.empty()) {
                    cout << "No patients waiting.\n";
                } else {
                    cout << "Waiting patients:\n";
                    queue<Patient_TRP> temp_TRP = clinicQueue_TRP;
                    while(!temp_TRP.empty()) {
                        cout << temp_TRP.front().name_TRP << endl;
                        temp_TRP.pop();
                    }
                }
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

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS26.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

--- Clinic Menu ---
1. Check-in patient
2. Assign next patient to doctor
3. Display waiting patients
0. Exit
Enter your choice: 1
Enter patient name: Riya
Riya has checked in.

Enter your choice: 1
Enter patient name: Karan
Karan has checked in.

Enter your choice: 1
Enter patient name: Asha
Asha has checked in.

Enter your choice: 3
Waiting patients:
Riya
Karan
Asha

Enter your choice: 2
Enter doctor's name: Mehta
Patient Riya assigned to Dr. Mehta

Enter your choice: 2
Enter doctor's name: Shah
Patient Karan assigned to Dr. Shah

Enter your choice: 3
Waiting patients:
Asha

Enter your choice: 0
Exiting...


