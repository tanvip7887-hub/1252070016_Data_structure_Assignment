/*Write a program to keep track of patients as they checked into a medical clinic, assigning patients to doctors on a first-come, 
first-served basis.*/

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
