
ASSIGNMENT 10
==============

AIM : Write a program to arrange the list of employees as per the average of their height and weight by using Merge and Selection sorting method. Analyse their time complexities and conclude which algorithm will take less time to sort the list. 

THEORY :
--------

1) Selection Sort is a simple sorting technique that repeatedly selects the minimum element and places it in the correct position, but it takes O(n²) time in all cases.

2) Merge Sort follows the Divide and Conquer strategy, dividing the list into halves, sorting them, and merging, with O(n log n) time complexity.

3) In this program we have to calculate the average of height and weight and sort it by using selection sort and merge sort.

4) After this, we have to Analyse their time complexities and conclude which algorithm will take less time to sort the list


ALGORITHM :
-----------

Algorithm Employee_Sorting
1.  Start

2.  Input n → number of employees

3.  For i ← 1 to n do
4.      Read employee id, name, height, weight
5.      avg[i] ← (height + weight) / 2
6.      Store record in array A
7.  End For

8.  Repeat
9.      Print menu:
            1 - Selection Sort
            2 - Merge Sort
            3 - Exit
10.     Read choice

11.     If choice = 1 then
12.         Call Selection_Sort(A, n)
13.         Display sorted employees with averages
14.         Print Time Complexity = O(n²)

15.     Else if choice = 2 then
16.         Call Merge_Sort(A, 0, n-1)
17.         Display sorted employees with averages
18.         Print Time Complexity = O(n log n)

19.     Else if choice = 3 then
20.         Exit
21.     End If

22. Until choice = 3

23. Conclude:
        Merge Sort takes less time than Selection Sort 
        for large lists because O(n log n) < O(n²)

24. Stop


PROGRAM :
---------
```cpp
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
```

OUTPUT :
---------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>G++ ASS10.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter number of employees: 5


EMPLOYEE DETAILS

-----------------------------------------------------

Employee 1
Employee id = 1
Employee name = Yash
Employee height = 6.5
Employee weight = 5
Average of height and weight = 5.75

Employee 2
Employee id = 2
Employee name = Tanvi
Employee height = 6
Employee weight = 5
Average of height and weight = 5.5

Employee 3
Employee id = 3
Employee name = Rohan
Employee height = 6.6
Employee weight = 23
Average of height and weight = 14.8

Employee 4
Employee id = 4
Employee name = Isha
Employee height = 5.8
Employee weight = 6
Average of height and weight = 5.9

Employee 5
Employee id = 5
Employee name = Sahil
Employee height = 6.5
Employee weight = 2
Average of height and weight = 4.25

-----------------------------------------------------

1 - Selection sort
2 - Merge sort
3 - Exit

Enter choice: 1

PASS-1
Swapped Employee ID 5 and 1
Array state (Employee IDs by average): 5(4.25) 2(5.5) 3(14.8) 4(5.9) 1(5.75)

------------------------------------------------------------------------

PASS-2
No swapping needed
Array state (Employee IDs by average): 5(4.25) 2(5.5) 3(14.8) 4(5.9) 1(5.75)

------------------------------------------------------------------------

PASS-3
Swapped Employee ID 1 and 3
Array state (Employee IDs by average): 5(4.25) 2(5.5) 1(5.75) 4(5.9) 3(14.8)

------------------------------------------------------------------------

PASS-4
No swapping needed
Array state (Employee IDs by average): 5(4.25) 2(5.5) 1(5.75) 4(5.9) 3(14.8)

------------------------------------------------------------------------


After Sorting (Selection sort)

-----------------------------------------------------

Employee 1
Employee id = 5
Employee name = Sahil
Employee height = 6.5
Employee weight = 2
Average of height and weight = 4.25

Employee 2
Employee id = 2
Employee name = Tanvi
Employee height = 6
Employee weight = 5
Average of height and weight = 5.5

Employee 3
Employee id = 1
Employee name = Yash
Employee height = 6.5
Employee weight = 5
Average of height and weight = 5.75

Employee 4
Employee id = 4
Employee name = Isha
Employee height = 5.8
Employee weight = 6
Average of height and weight = 5.9

Employee 5
Employee id = 3
Employee name = Rohan
Employee height = 6.6
Employee weight = 23
Average of height and weight = 14.8

-----------------------------------------------------

1 - Selection sort
2 - Merge sort
3 - Exit
Enter choice: 2

After Sorting (Merge sort)

-----------------------------------------------------

Employee 1
Employee id = 5
Employee name = Sahil
Employee height = 6.5
Employee weight = 2
Average of height and weight = 4.25

Employee 2
Employee id = 2
Employee name = Tanvi
Employee height = 6
Employee weight = 5
Average of height and weight = 5.5

Employee 3
Employee id = 1
Employee name = Yash
Employee height = 6.5
Employee weight = 5
Average of height and weight = 5.75

Employee 4
Employee id = 4
Employee name = Isha
Employee height = 5.8
Employee weight = 6
Average of height and weight = 5.9

Employee 5
Employee id = 3
Employee name = Rohan
Employee height = 6.6
Employee weight = 23
Average of height and weight = 14.8

-----------------------------------------------------

1 - Selection sort
2 - Merge sort
3 - Exit
Enter choice: 3

Exiting...



SELECTION SORT ( DRY RUN ) :
-----------------------------



![alt text](image-15.png)




![alt text](image-16.png)




MERGE SORT ( DRY RUN ) :
-------------------------


![alt text](image-17.png)




![alt text](image-18.png)




![alt text](image-19.png)










