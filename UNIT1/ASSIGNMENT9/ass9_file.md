
ASSIGNMENT 9
=============

AIM : Write a program using Bubble sort algorithm, assign the roll nos. to the students of your class as per their previous years result. i.e. 
topper will be roll no. 1 and analyse the sorting algorithm pass by pass.


THEORY :
---------


1) Bubble Sort is a simple comparison-based sorting algorithm.

2) It repeatedly compares adjacent elements and swaps them if they are in the wrong order.

3) After each pass, the largest element moves to its correct position (like bubbles rising to the top).

4) Time complexity: Best case = O(n), Worst case = O(n²), Average case = O(n²).

5) In this program, students are sorted by marks, and roll numbers are assigned based on rank (topper gets Roll No. 1).


ALGORITHM :
-----------


Algorithm Bubble_Sort_Assign_RollNos

1.  Start

2.  Input n → number of students

3.  For i ← 1 to n do
4.      Read student name and marks
5.      Store record in array A
6.  End For

7.  For pass ← 1 to n-1 do
8.      For j ← 0 to n-pass-1 do
9.          If A[j].marks < A[j+1].marks then
10.             Swap A[j] and A[j+1]
11.         End If
12.     End For
13.     Display array state after current pass
14. End For

15. For i ← 0 to n-1 do
16.     Assign roll_no ← i+1  (since highest marks at beginning)
17.     Print student name, marks, and assigned roll number
18. End For

19. Print Time Complexity = O(n²)

20. Stop


PROGRAM :
---------

```cpp
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
```


OUTPUT :
--------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS9.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter number of students: 5

Enter marks of Yash: 89
Enter marks of Kirti: 76
Enter marks of Arjun: 90
Enter marks of Tanvi: 45
Enter marks of Kirti: 76

Before Sorting

1 Yash 89
2 Kirti 76
3 Arjun 90
4 Tanvi 45
5 Kirti 76

After Sorting (by marks descending)

3 Arjun 90
1 Yash 89
2 Kirti 76
5 Kirti 76
4 Tanvi 45

----------------------------------------------

Maximum marks: 90
Minimum marks: 45

----------------------------------------------


BUBBLE SORT ( DRY RUN ) :
---------------------------

![alt text](image-13.png)




![alt text](image-14.png)








