
ASSIGNMENT 7
=============

AIM : WAP to implement Bubble sort and Quick Sort on a 1D array of Student structure (contains student_name, student_roll_no, total_marks),
with key as student_roll_no. And count the number of swap performed by each method.


THEORY :
---------

1) Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order, “bubbling” the largest to the end.

2) Quick Sort is a divide-and-conquer algorithm that partitions the array around a pivot element and recursively sorts the partitions.

3) Bubble Sort is simple but has time complexity O(n²) in best, average, and worst cases.

4) Quick Sort is more efficient, with average and best time complexity O(n log n) but worst-case O(n²).

5) In this program, both algorithms sort student records by roll number and count the number of swaps performed.


ALGORITHM :
------------

Algorithm Student_Sorting

1.  Start

2.  Input n → number of students

3.  For i ← 1 to n do
4.      Read student_name, student_roll_no, total_marks
5.      Store record in array A
6.  End For

7.  Call Bubble_Sort(A, n) and count swaps
8.  Display sorted list (Bubble Sort) and swap count

9.  Call Quick_Sort(A, 0, n-1) and count swaps
10. Display sorted list (Quick Sort) and swap count

11. Stop

Algorithm Bubble_Sort(A, n)

1.  swap_count ← 0
2.  For pass ← 1 to n-1 do
3.      For j ← 0 to n-pass-1 do
4.          If A[j].roll_no > A[j+1].roll_no then
5.              Swap A[j], A[j+1]
6.              swap_count ← swap_count + 1
7.          End If
8.      End For
9.  End For
10. Return swap_count

Algorithm Partition(A, lb, ub)

1.  pivot ← A[lb].roll_no
2.  start ← lb , end ← ub
3.  While start < end do
4.      While A[start].roll_no ≤ pivot and start < ub do
5.          start ← start + 1
6.      End While
7.      While A[end].roll_no > pivot and end > lb do
8.          end ← end - 1
9.      End While
10.     If start < end then
11.         Swap A[start], A[end]
12.         swap_count ← swap_count + 1
13.     End If
14. End While
15. Swap A[lb], A[end]
16. swap_count ← swap_count + 1
17. Return end


PROGRAM :
----------

```CPP
#include <iostream>
#include <cstring>
using namespace std;

int quick_swap_TRP = 0, bubble_swap_TRP = 0;

struct Student
{
    int roll_TRP;
    char name_TRP[100];
    int total_marks_TRP;
};

void Bubble_TRP(Student *st, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (st[j].roll_TRP > st[j + 1].roll_TRP)
            {
                Student temp_TRP = st[j];
                st[j] = st[j + 1];
                st[j + 1] = temp_TRP;
                bubble_swap_TRP++;
            }
        }
    }
}

int partition_TRP(Student *st, int lb, int ub)
{
    Student pivot_TRP = st[lb];
    int start_TRP = lb, end_TRP = ub;

    while (start_TRP < end_TRP)
    {
        while (st[start_TRP].roll_TRP <= pivot_TRP.roll_TRP && start_TRP < ub)
            start_TRP++;

        while (st[end_TRP].roll_TRP > pivot_TRP.roll_TRP && end_TRP > lb)
            end_TRP--;

        if (start_TRP < end_TRP)
        {
            Student temp_TRP = st[start_TRP];
            st[start_TRP] = st[end_TRP];
            st[end_TRP] = temp_TRP;
            quick_swap_TRP++;
        }
    }

    st[lb] = st[end_TRP];
    st[end_TRP] = pivot_TRP;
    quick_swap_TRP++;
    return end_TRP;
}

void Quick_TRP(Student *st, int lb, int ub)
{
    if (lb < ub)
    {
        int loc_TRP = partition_TRP(st, lb, ub);
        Quick_TRP(st, lb, loc_TRP - 1);
        Quick_TRP(st, loc_TRP + 1, ub);
    }
}

int main()
{
    Student *st = NULL, *stt = NULL;
    int num_TRP, OP_TRP;

    cout << "Enter number of student: ";
    cin >> num_TRP;

    st = new Student[num_TRP];
    stt = new Student[num_TRP];

    const char *names_TRP[] = {"Abir", "Aarav", "Isha", "Rohan", "Priya", "Vikas", "Neha", "Sahil", "Anaya", "Dev", "Kriti",
                               "Mira", "Kabir", "Tanvi", "Yash", "Riya", "Arjun", "Asha", "Nikhil", "Pooja", "Kunal", "Vishal", "Amir", "Sharukh", "Salman", "Mrunal", "Kirti"};
    const int N_NAMES_TRP = sizeof(names_TRP) / sizeof(names_TRP[0]);

    const int rollno_TRP[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    const int N_ROLL_TRP = sizeof(rollno_TRP) / sizeof(rollno_TRP[0]);

    const int total_m_TRP[] = {400, 390, 456, 178, 389, 467, 298, 498, 500, 498, 375, 785, 467, 563};
    const int N_TOTAL_TRP = sizeof(total_m_TRP) / sizeof(total_m_TRP[0]);

    // Fill n records using rand()
    for (int i = 0; i < num_TRP; i++)
    {
        st[i].roll_TRP = rollno_TRP[rand() % N_ROLL_TRP];
        strcpy(st[i].name_TRP, names_TRP[rand() % N_NAMES_TRP]);
        st[i].total_marks_TRP = total_m_TRP[rand() % N_TOTAL_TRP];

        stt[i].roll_TRP = st[i].roll_TRP;
        strcpy(stt[i].name_TRP, st[i].name_TRP);
        stt[i].total_marks_TRP = st[i].total_marks_TRP;
    }

    cout << "Records are:\n\n";
    for (int i = 0; i < num_TRP; i++)
    {
        cout << "ROLL NO: " << stt[i].roll_TRP << endl;
        cout << "NAME: " << stt[i].name_TRP << endl;
        cout << "TOTAL MARKS: " << stt[i].total_marks_TRP << endl;
        cout << "\n----------------------------------------------------------------------------\n";
    }

    cout << "----------------------------------------------------------------------------\n\n";

    do
    {
        cout << "\n\n1-Bubble sort\n2-Quick sort\n3-Exit\n";
        cout << "Enter correct choice: ";
        cin >> OP_TRP;

        switch (OP_TRP)
        {
        case 1:
            Bubble_TRP(st, num_TRP);
            cout << "Sorted Records are:\n";
            for (int i = 0; i < num_TRP; i++)
            {
                cout << "ROLL NO: " << st[i].roll_TRP << endl;
                cout << "NAME: " << st[i].name_TRP << endl;
                cout << "TOTAL MARKS: " << st[i].total_marks_TRP << endl;
                cout << "\n----------------------------------------------------------------------------\n";
            }
            cout << "No. of swaps: " << bubble_swap_TRP << endl;
            cout << "----------------------------------------------------------------------------\n\n";
            break;

        case 2:
            Quick_TRP(stt, 0, num_TRP - 1);
            cout << "Sorted Records are:\n";
            for (int i = 0; i < num_TRP; i++)
            {
                cout << "ROLL NO: " << stt[i].roll_TRP << endl;
                cout << "NAME: " << stt[i].name_TRP << endl;
                cout << "TOTAL MARKS: " << stt[i].total_marks_TRP << endl;
                cout << "\n----------------------------------------------------------------------------\n";
            }
            cout << "No. of swaps: " << quick_swap_TRP << endl;
            cout << "----------------------------------------------------------------------------\n\n";
            break;

        case 3:
            cout << "Enter any key to exit..\n";
            break;

        default:
            cout << "Enter correct choice\n";
        }
    } while (OP_TRP != 3);

    delete[] st;
    delete[] stt;

    return 0;
}
```

OUTPUT :
----------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>G++ ASS7.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe
Enter number of student: 4

Records are:

ROLL NO: 12
NAME: Kirti
TOTAL MARKS: 298

----------------------------------------------------------------------------
ROLL NO: 11
NAME: Kirti
TOTAL MARKS: 456

----------------------------------------------------------------------------
ROLL NO: 19
NAME: Dev
TOTAL MARKS: 467

----------------------------------------------------------------------------
ROLL NO: 15
NAME: Anaya
TOTAL MARKS: 467

----------------------------------------------------------------------------
----------------------------------------------------------------------------



1-Bubble sort
2-Quick sort
3-Exit
Enter correct choice: 1

Sorted Records are:

ROLL NO: 11
NAME: Kirti
TOTAL MARKS: 456

----------------------------------------------------------------------------
ROLL NO: 12
NAME: Kirti
TOTAL MARKS: 298

----------------------------------------------------------------------------
ROLL NO: 15
NAME: Anaya
TOTAL MARKS: 467

----------------------------------------------------------------------------
ROLL NO: 19
NAME: Dev
TOTAL MARKS: 467

----------------------------------------------------------------------------
No. of swaps: 2
----------------------------------------------------------------------------

1-Bubble sort
2-Quick sort
3-Exit

Enter correct choice: 2

Sorted Records are:
ROLL NO: 11
NAME: Kirti
TOTAL MARKS: 456

----------------------------------------------------------------------------
ROLL NO: 12
NAME: Kirti
TOTAL MARKS: 298

----------------------------------------------------------------------------
ROLL NO: 15
NAME: Anaya
TOTAL MARKS: 467

----------------------------------------------------------------------------
ROLL NO: 19
NAME: Dev
TOTAL MARKS: 467

----------------------------------------------------------------------------
No. of swaps: 2
----------------------------------------------------------------------------

1-Bubble sort
2-Quick sort
3-Exit
Enter correct choice: 3

Enter any key to exit..


BUBBLE SORT ( DRY RUN ) :
--------------------------




![alt text](image-1.png)





![alt text](image-2.png)





QUICK SORT ( DRY RUN ) :
--------------------------




![alt text](image-3.png)





![alt text](image-4.png)





![alt text](image-5.png)





![alt text](image-6.png)





![alt text](image-7.png)










