/*Write a program using Bubble sort algorithm, assign the roll nos. to the students of your class as per their previous years result. i.e. 
topper will be roll no. 1 and analyse the sorting algorithm pass by pass.*/

#include <iostream>
#include <cstring>
using namespace std;

struct Student_TRP
{
    int Roll_TRP;
    char name_TRP[30];
    int mark_TRP;
};

void bubble_TRP(Student_TRP *S_TRP, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (S_TRP[j].mark_TRP < S_TRP[j + 1].mark_TRP)
            {
                Student_TRP temp = S_TRP[j];
                S_TRP[j] = S_TRP[j + 1];
                S_TRP[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int num_student_TRP;
    Student_TRP *S_TRP = NULL;

    cout << "Enter number of students: ";
    cin >> num_student_TRP;

    S_TRP = new Student_TRP[num_student_TRP];
    if (S_TRP == NULL)
    {
        cout << "Memory not allocated\n";
        exit(-1);
    }

    const char *names_TRP[] = {"Abir", "Aarav", "Isha", "Rohan", "Priya", "Vikas", "Neha", "Sahil", "Anaya", "Dev", "Kriti",
                               "Mira", "Kabir", "Tanvi", "Yash", "Riya", "Arjun", "Asha", "Nikhil", "Pooja", "Kunal", "Vishal",
                               "Amir", "Sharukh", "Salman", "Mrunal", "Kirti"};
    const int N_NAMES_TRP = sizeof(names_TRP) / sizeof(names_TRP[0]);

    // Assign roll numbers and random names
    for (int i = 0; i < num_student_TRP; i++)
    {
        S_TRP[i].Roll_TRP = i + 1;
        strcpy(S_TRP[i].name_TRP, names_TRP[rand() % N_NAMES_TRP]);
    }

    // Enter marks manually
    for (int i = 0; i < num_student_TRP; i++)
    {
        cout << "Enter marks of " << S_TRP[i].name_TRP << ": ";
        cin >> S_TRP[i].mark_TRP;
    }

    cout << "\nBefore Sorting\n";
    for (int i = 0; i < num_student_TRP; i++)
    {
        cout << S_TRP[i].Roll_TRP << " "
             << S_TRP[i].name_TRP << " "
             << S_TRP[i].mark_TRP << endl;
    }

    bubble_TRP(S_TRP, num_student_TRP);

    cout << "\nAfter Sorting (by marks descending)\n";
    for (int i = 0; i < num_student_TRP; i++)
    {
        cout << S_TRP[i].Roll_TRP << " "
             << S_TRP[i].name_TRP << " "
             << S_TRP[i].mark_TRP << endl;
    }

    cout << "\n----------------------------------------------\n";
    cout << "Maximum marks: " << S_TRP[0].mark_TRP << endl;
    cout << "Minimum marks: " << S_TRP[num_student_TRP - 1].mark_TRP << endl;
    cout << "----------------------------------------------\n";

    delete[] S_TRP;
    return 0;
}
