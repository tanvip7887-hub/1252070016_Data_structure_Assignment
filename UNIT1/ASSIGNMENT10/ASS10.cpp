/*Write a program to arrange the list of employees as per the average of their height and weight by using Merge and Selection sorting method. 
Analyse their time complexities and conclude which algorithm will take less time to sort the list. */

#include <iostream>
#include <cstring>
using namespace std;

struct Employee 
{
    int emp_id_TRP;
    char emp_name_TRP[40];
    float emp_height_TRP;
    int emp_weight_TRP;
};

Employee* b = NULL;  

float average_TRP(Employee e) 
{
    return (e.emp_height_TRP + e.emp_weight_TRP) / 2.0;
}

void selection_sort_TRP(Employee* parr, int num_TRP) 
{
    int s_TRP = 1;
    for (int i = 0; i < num_TRP - 1; i++) 
    {
        int loc_TRP = i;
        for (int j = i + 1; j < num_TRP; j++) 
        {
            if (average_TRP(parr[j]) < average_TRP(parr[loc_TRP]))
                loc_TRP = j;
        }

        if (loc_TRP != i) 
        {
            Employee temp_TRP = parr[i];
            parr[i] = parr[loc_TRP];
            parr[loc_TRP] = temp_TRP;

            cout << "PASS-" << s_TRP++ << endl;
            cout << "Swapped Employee ID " << parr[i].emp_id_TRP
                 << " and " << parr[loc_TRP].emp_id_TRP << endl;
            cout << "Array state (Employee IDs by average): ";
        } 
        else 
        {
            cout << "PASS-" << s_TRP++ << endl;
            cout << "No swapping needed" << endl;
            cout << "Array state (Employee IDs by average): ";
        }

        for (int m = 0; m < num_TRP; m++)
            cout << parr[m].emp_id_TRP << "(" << average_TRP(parr[m]) << ") ";
        cout << "\n------------------------------------------------------------------------\n\n";
    }
}

void merge_TRP(Employee* parr, int lb, int mid, int ub) 
{
    int i_TRP = lb;
    int j_TRP = mid + 1;
    int k_TRP = lb;

    while (i_TRP <= mid && j_TRP <= ub) 
    {
        if (average_TRP(parr[i_TRP]) < average_TRP(parr[j_TRP])) 
        {
            b[k_TRP++] = parr[i_TRP++];
        } 
        else 
        {
            b[k_TRP++] = parr[j_TRP++];
        }
    }

    while (i_TRP <= mid) 
    {
        b[k_TRP++] = parr[i_TRP++];
    }

    while (j_TRP <= ub) 
    {
        b[k_TRP++] = parr[j_TRP++];
    }

    for (i_TRP = lb; i_TRP <= ub; i_TRP++) 
    {
        parr[i_TRP] = b[i_TRP];
    }
}

void merge_sort_TRP(Employee* parr, int lb, int ub) 
{
    if (lb < ub) 
    {
        int mid_TRP = (lb + ub) / 2;
        merge_sort_TRP(parr, lb, mid_TRP);
        merge_sort_TRP(parr, mid_TRP + 1, ub);
        merge_TRP(parr, lb, mid_TRP, ub);
    }
}

void display(Employee* parr, int num_TRP)
 {
    cout << "\n-----------------------------------------------------\n\n";
    for (int i = 0; i < num_TRP; i++) {
        cout << "\nEmployee " << i + 1 << endl;
        cout << "Employee id = " << parr[i].emp_id_TRP << endl;
        cout << "Employee name = " << parr[i].emp_name_TRP << endl;
        cout << "Employee height = " << parr[i].emp_height_TRP << endl;
        cout << "Employee weight = " << parr[i].emp_weight_TRP << endl;
        cout << "Average of height and weight = " << average_TRP(parr[i]) << endl;
    }
    cout << "\n-----------------------------------------------------\n\n";
}

int main() 
{
    int num_TRP, choice_TRP;

    cout << "Enter number of employees: ";
    cin >> num_TRP;

    const char* name_TRP[] = {"Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil","Anaya","Dev",
                              "Kriti","Mira","Kabir","Tanvi","Yash","Riya","Arjun","Asha","Nikhil","Pooja",
                              "Kunal","Vishal","Amir","Sharukh","Salman","Mrunal","Kirti"};
    const int N_names_TRP = sizeof(name_TRP) / sizeof(name_TRP[0]);

    const float height_TRP[] = {4.6, 5.0, 4.0, 4.5, 5.5, 5.8, 3.9, 6.5, 6.6, 6.0};
    const int N_height_TRP = sizeof(height_TRP) / sizeof(height_TRP[0]);

    const int weight_TRP[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
                              21,22,23,24,25,26,27,28,29,30};
    const int N_weight_TRP = sizeof(weight_TRP) / sizeof(weight_TRP[0]);

    Employee* parr = new Employee[num_TRP];
    b = new Employee[num_TRP];

    for (int i = 0; i < num_TRP; i++) 
    {
        parr[i].emp_id_TRP = i + 1;
        strcpy(parr[i].emp_name_TRP, name_TRP[rand() % N_names_TRP]);
        parr[i].emp_height_TRP = height_TRP[rand() % N_height_TRP];
        parr[i].emp_weight_TRP = weight_TRP[rand() % N_weight_TRP];
    }

    cout << "\nEMPLOYEE DETAILS\n";
    display(parr, num_TRP);

    do 
    {
        cout << "\n\n1 - Selection sort\n2 - Merge sort\n3 - Exit\n";
        cout << "Enter choice: ";
        cin >> choice_TRP;

        switch (choice_TRP) 
        {
            case 1:
                selection_sort_TRP(parr, num_TRP);
                cout << "\nAfter Sorting (Selection sort)\n";
                display(parr, num_TRP);
                break;

            case 2:
                merge_sort_TRP(parr, 0, num_TRP - 1);
                cout << "\nAfter Sorting (Merge sort)\n";
                display(parr, num_TRP);
                break;

            case 3:
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nEnter correct choice..\n";
        }

    } 
    while (choice_TRP != 3);

    delete[] parr;
    delete[] b;

    return 0;
}
