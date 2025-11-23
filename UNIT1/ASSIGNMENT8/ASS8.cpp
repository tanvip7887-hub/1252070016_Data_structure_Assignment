/*Write a program to input marks of n students Sort the marks in ascending order using the Quick Sort algorithm without using built-in 
library functions and analyse the sorting algorithm pass by pass. Find the minimum and maximum marks using Divide and Conquer (recursively).*/

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


























































