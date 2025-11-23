
ASSIGNMENT 8
==============

AIM : Write a program to input marks of n students Sort the marks in ascending order using the Quick Sort algorithm without using built-in 
library functions and analyse the sorting algorithm pass by pass. Find the minimum and maximum marks using Divide and Conquer (recursively).


THEORY :
--------

1) Quick Sort is a Divide and Conquer sorting algorithm.

2) It works by choosing a pivot element, then placing all smaller elements to the left and all greater elements to the right of the pivot.

3) The process is applied recursively on the left and right subarrays until the whole array is sorted.

4) Time complexity:

    Best case = O(n log n)
    Average case = O(n log n)
    Worst case = O(n²) (if pivots are always poorly chosen, e.g., already sorted data with last element as pivot).



ALGORITHM :
------------


Algorithm Student_Marks_QuickSort

1.  Start

2.  Input n → number of students
3.  Read marks of n students into array A

4.  Call Quick_Sort(A, 0, n-1)

5.  Print sorted marks in ascending order

6.  Call Find_Min_Max(A, low, high) to get minimum and maximum marks

7.  Stop

Algorithm Quick_Sort(A, lb, ub)

1.  If lb < ub then
2.      pos ← Partition(A, lb, ub)
3.      Quick_Sort(A, lb, pos-1)
4.      Quick_Sort(A, pos+1, ub)
5.  End If

Algorithm Partition(A, lb, ub)

1.  pivot ← A[lb]
2.  start ← lb , end ← ub
3.  While start < end do
4.      While A[start] ≤ pivot and start < ub do
5.          start ← start + 1
6.      End While
7.      While A[end] > pivot and end > lb do
8.          end ← end - 1
9.      End While
10.     If start < end then
11.         Swap A[start], A[end]
12.     End If
13. End While
14. Swap A[lb], A[end]   // place pivot at correct position
15. Return end

Algorithm Find_Min_Max(A, low, high)

1.  If low = high then
2.      min ← A[low] , max ← A[low]
3.  Else if high = low + 1 then
4.      If A[low] < A[high] then
5.          min ← A[low] , max ← A[high]
6.      Else
7.          min ← A[high] , max ← A[low]
8.  Else
9.      mid ← (low + high) / 2
10.     (min1, max1) ← Find_Min_Max(A, low, mid)
11.     (min2, max2) ← Find_Min_Max(A, mid+1, high)
12.     min ← minimum(min1, min2)
13.     max ← maximum(max1, max2)
14. End If
15. Return (min, max)


PROGRAM :
----------

```cpp
#include <iostream>
using namespace std;

int num_TRP, i_TRP = 0;

int partition_TRP(int *parr, int lb, int ub)
{
    int start_TRP = lb;
    int end_TRP = ub;
    int pivot_TRP = parr[lb];

    cout << "---------------------------------------\n";
    cout << "Pass " << ++i_TRP << "\n\n";
    cout << "Pivot is " << pivot_TRP << "\n\n";

    while (start_TRP < end_TRP)
    {
        while (parr[start_TRP] <= pivot_TRP && start_TRP < ub)
            start_TRP++;

        while (parr[end_TRP] > pivot_TRP && end_TRP > lb)
            end_TRP--;

        if (start_TRP < end_TRP)
        {
            if(parr[start_TRP] != parr[end_TRP])
            {
                cout << "Swap " << parr[start_TRP] << " and " << parr[end_TRP] << "\n";
            }
            else
            {
                cout<<"No swapping needed.."<<endl;
            }

            for (int i = 0; i < num_TRP; i++)
                cout << parr[i] << " ";
            cout << endl;

            int temp_TRP = parr[start_TRP];
            parr[start_TRP] = parr[end_TRP];
            parr[end_TRP] = temp_TRP;
        }
    }

     if(pivot_TRP != parr[end_TRP])
    {
            cout << "\n\nAfter placing pivot at its correct place: ";
            cout << "Swap (pivot) " << pivot_TRP << " and " << parr[end_TRP] << "\n";
             parr[lb] = parr[end_TRP];
             parr[end_TRP] = pivot_TRP;

    }
    else
    {
        cout<<"Pivot is at correct position "<<endl;
    }

    for (int i = 0; i < num_TRP; i++)
        cout << parr[i] << " ";

    cout << "\n";
    cout << "---------------------------------------\n";
    return end_TRP;
}

void Quick_TRP(int *parr, int lb, int ub)
{
    if (lb < ub)
    {
        int part_TRP = partition_TRP(parr, lb, ub);
        Quick_TRP(parr, lb, part_TRP - 1);
        Quick_TRP(parr, part_TRP + 1, ub);
    }
}

int main()
{
    int *parr = NULL;

    cout << "Enter no. of students: ";
    cin >> num_TRP;

    parr = new int[num_TRP];
    if (parr == NULL)
    {
        cout << "Memory not allocated..\n";
        exit(-1);
    }

    cout << "Enter marks of " << num_TRP << " students (total marks=100): ";
    for (int i = 0; i < num_TRP; i++)
        cin >> parr[i];

    Quick_TRP(parr, 0, num_TRP - 1);

    cout << "\nSorted marks:\n";
    for (int i = 0; i < num_TRP; i++)
        cout << parr[i] << " ";

    delete[] parr;
    return 0;
}
```


OUTPUT :
---------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS8.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe
Enter no. of students: 3
Enter marks of 3 students (total marks=100): 67 45 90

-------------------------------------------------------------
Pass 1

Pivot is 67


After placing pivot at its correct place: Swap (pivot) 67 and 45
45 67 90

----------------------------------------------------------------

Sorted marks:
45 67 90



QUICK SORT ( DRY RUN ) :
-------------------------


![alt text](image-11.png)




![alt text](image-12.png)




![alt text](image-8.png)




![alt text](image-9.png)




![alt text](image-10.png)

















































