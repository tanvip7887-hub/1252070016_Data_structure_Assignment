
ASSIGNMENT 3
==============

AIM : Implement matrix multiplication and analyse its performance using row-major vs column-major order access patterns to understandnhow memory layout affects cache performance.

THEORY :
----------

1) Row-Major Order -> Elements of each row are stored continuously in memory (used in C/C++).

2) Column-Major Order –> Elements of each column are stored continuously in memory (used in Fortran/MATLAB).

3) Row-Major Multiplication –> Multiply matrices row-wise, cache friendly, faster in C++.

4) Column-Major Multiplication –>  Multiply matrices column-wise, causes cache misses, slower in C++.

5) Time Analysis done using clock() in C++ to compare row vs column execution time.

ALGORITHM :
------------

Algorithm Matrix_Multiplication_Analysis

1. Start

2. Input m_TRP → number of rows of arr1
3. Input n_TRP → number of columns of arr1 / rows of arr2
4. Input p_TRP → number of columns of arr2

5. Allocate arr1_TRP[m_TRP][n_TRP], arr2_TRP[n_TRP][p_TRP], arr3_TRP[m_TRP][p_TRP]

6. Input elements of arr1_TRP
7. Input elements of arr2_TRP

8. Initialize arr3_TRP with 0

9. // Row-major order multiplication
10. Start timer
11. For i = 0 to m_TRP-1
       For k = 0 to n_TRP-1
           temp_TRP ← arr1_TRP[i][k]
           For j = 0 to p_TRP-1
               arr3_TRP[i][j] += temp_TRP * arr2_TRP[k][j]
12. Stop timer
13. Print arr3_TRP (Result Row-Major)
14. Print runtime

15. Initialize arr3_TRP with 0

16. // Column-major order multiplication (simulation)
17. Start timer
18. For j = 0 to p_TRP-1
       For k = 0 to n_TRP-1
           temp_TRP ← arr2_TRP[k][j]
           For i = 0 to m_TRP-1
               arr3_TRP[i][j] += arr1_TRP[i][k] * temp_TRP
19. Stop timer
20. Print arr3_TRP (Result Column-Major)
21. Print runtime

22. Free memory allocated for arr1_TRP, arr2_TRP, arr3_TRP

23. Stop


PROGRAM :
----------

```cpp
#include<iostream>
#include<ctime>
using namespace std;

int main()
{
    int m_TRP, n_TRP, p_TRP;
    clock_t start_TRP, stop_TRP;
    double runtime_TRP;
    int **arr1_TRP=NULL, **arr2_TRP=NULL, **arr3_TRP=NULL;

    cout<<"Enter rows of arr1 (m): ";
    cin>>m_TRP;
    cout<<"Enter cols of arr1 / rows of arr2 (n): ";
    cin>>n_TRP;
    cout<<"Enter cols of arr2 (p): ";
    cin>>p_TRP;

    //arr1
     arr1_TRP= new int*[m_TRP]; 
     if(arr1_TRP==NULL)
      { cout<<"Memory not allocated"<<endl; 
        exit(0); 
      } 

      for (int i = 0; i < m_TRP; i++) 
      { 
        arr1_TRP[i] = new int[n_TRP];
        if( arr1_TRP[i] == NULL)
        { 
            cout<<" memory not allocated"<<endl;
            for(int j=0; j<i; j++) 
            { 
                delete arr1_TRP[j]; 
            } 
            delete[] arr1_TRP; 
            exit(0); 
        }
     } 
     
     //arr2 
    arr2_TRP= new int*[n_TRP];
    if(arr2_TRP==NULL)
    { cout<<"Memory not allocated"<<endl; 
      exit(0); 
    } 

    for (int i = 0; i < n_TRP; i++) 
    { 
       arr2_TRP[i]= new int[p_TRP];

      if(arr2_TRP==NULL)
      {
         cout<<"Memory not allocated"<<endl;
          for(int j=0; j<i; j++) 
          {
             delete arr2_TRP[j];
         } 
         delete[] arr2_TRP; 
         exit(0);
        } 
    }

    //arr3
    arr3_TRP= new int*[m_TRP];

    if(arr3_TRP==NULL)
    { cout<<"Memory not allocated"<<endl; 
      exit(0); 
    } 

    for (int i = 0; i < m_TRP; i++)
    { 
        arr3_TRP[i] = new int[p_TRP]; 
        
        if( arr3_TRP[i] == NULL) 
        { 
            cout<<" memory not allocated"<<endl;
                
            for(int j=0; j<i; j++) 
                { 
                delete arr3_TRP[j];
                } 
                delete[] arr3_TRP; 
                exit(0);
        }
    }
    
    cout<<"Enter "<<m_TRP * n_TRP<<" elements for arr1: ";
    for (int i = 0; i < m_TRP; i++)
        for (int j = 0; j < n_TRP; j++)
            cin>>arr1_TRP[i][j];

    
    cout<<"Enter "<<n_TRP * p_TRP<<" elements for arr2: ";
    for (int i = 0; i < n_TRP; i++)
        for (int j = 0; j < p_TRP; j++)
            cin>>arr2_TRP[i][j];

    // initialize arr3
    for (int i = 0; i < m_TRP; i++)
        for (int j = 0; j < p_TRP; j++)
            arr3_TRP[i][j] = 0;

    //Row-major multiplication
    start_TRP = clock();

    for (int i = 0; i < m_TRP; i++) 
    {
        for (int k = 0; k < n_TRP; k++) 
        {
            int temp_TRP = arr1_TRP[i][k];  
            for (int j = 0; j < p_TRP; j++) 
            {
                arr3_TRP[i][j] += temp_TRP * arr2_TRP[k][j];
            }
        }
    }

    stop_TRP = clock();
    runtime_TRP = (double)(stop_TRP - start_TRP) / CLOCKS_PER_SEC;

    cout<<"Result (Row-Major Order): "<<endl;
    for (int i = 0; i < m_TRP; i++) 
    {
        for (int j = 0; j < p_TRP; j++)
            cout<<arr3_TRP[i][j]<<" ";

        cout<<endl;
    }
    cout<<"Runtime (Row-Major): "<<runtime_TRP<<" seconds"<<endl;

    //Column-major multiplication 
    for (int i = 0; i < m_TRP; i++)
        for (int j = 0; j < p_TRP; j++)
            arr3_TRP[i][j] = 0;

    start_TRP = clock();

    for (int j = 0; j < p_TRP; j++) 
    {          
        for (int k = 0; k < n_TRP; k++)
        {
            int temp_TRP = arr2_TRP[k][j]; 

            for (int i = 0; i < m_TRP; i++) 
            {
                arr3_TRP[i][j] += arr1_TRP[i][k] * temp_TRP;
            }
        }
    }

    stop_TRP = clock();
    runtime_TRP = (double)(stop_TRP - start_TRP) / CLOCKS_PER_SEC;

    cout<<"Result (Column-Major Simulation): "<<endl;
    for (int i = 0; i < m_TRP; i++) 
    {
        for (int j = 0; j < p_TRP; j++)
            cout<<arr3_TRP[i][j]<<" ";

        cout<<endl;
    }
    cout<<"Runtime (Column-Major): "<<runtime_TRP<<" seconds"<<endl;

    // free memory
    for (int i = 0; i < m_TRP; i++) 
        delete[] arr1_TRP[i];

    for (int i = 0; i < n_TRP; i++) 
        delete[] arr2_TRP[i];

    for (int i = 0; i < m_TRP; i++) 
        delete[] arr3_TRP[i];

    delete[] arr1_TRP;
    delete[] arr2_TRP;
    delete[] arr3_TRP;

    return 0;
}
```

OUTPUT :
---------
C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS3.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter rows of arr1 (m): 3
Enter cols of arr1 / rows of arr2 (n): 2
Enter cols of arr2 (p): 3

Enter 6 elements for arr1: 1 2 3 4 5 6
Enter 6 elements for arr2: 6 5 4 3 2 1

Result (Row-Major Order):
12 9 6
30 23 16
48 37 26

Runtime (Row-Major): 0 seconds

Result (Column-Major Simulation):
12 9 6
30 23 16
48 37 26

Runtime (Column-Major): 0 seconds