
ASSIGNMENT 5
=============

AIM  : Develop a program to identify and efficiently store a sparse matrix using compact representation and perform basic operations like display 
and simple transpose.

THEORY :
---------

1) A matrix with most of its elements as zero.

2) Instead of storing all elements, store only non-zero elements using triplet form (row, col, value).

3) Saves storage by not keeping zeros.

4) Shows the triplet representation of the matrix.

5) Swap row and column indices in triplet form to get the transpose matrix.

ALGORITHM :
------------

Algorithm Sparse_Matrix_Operations

1.  Start

2.  Input row_TRP → number of rows
3.  Input col_TRP → number of columns

4.  Allocate original matrix parr_TRP[row_TRP][col_TRP]

5.  Input elements of parr_TRP
6.  Initialize count_TRP ← 0
7.  For each element in parr_TRP
      If element ≠ 0 then
          count_TRP ← count_TRP + 1
      End If
8.  End For

9.  Display original matrix parr_TRP

10. Allocate sparse_TRP[count_TRP + 1][3]

11. Fill first row of sparse_TRP:
      sparse_TRP[0][0] ← row_TRP
      sparse_TRP[0][1] ← col_TRP
      sparse_TRP[0][2] ← count_TRP

12. Initialize m ← 1
13. For i ← 0 to row_TRP-1
      For j ← 0 to col_TRP-1
          If parr_TRP[i][j] ≠ 0 then
              sparse_TRP[m][0] ← i
              sparse_TRP[m][1] ← j
              sparse_TRP[m][2] ← parr_TRP[i][j]
              m ← m + 1
          End If
      End For
14. End For

15. Display sparse_TRP (Compact Representation)

16. Allocate transpose_TRP[count_TRP + 1][3]

17. Fill first row of transpose_TRP:
      transpose_TRP[0][0] ← sparse_TRP[0][1]  // number of columns becomes rows
      transpose_TRP[0][1] ← sparse_TRP[0][0]  // number of rows becomes columns
      transpose_TRP[0][2] ← sparse_TRP[0][2]  // number of non-zero elements

18. Initialize m ← 1
19. For i ← 0 to sparse_TRP[0][1]-1  // for each column of original matrix
      For j ← 1 to count_TRP
          If sparse_TRP[j][1] = i then
              transpose_TRP[m][0] ← sparse_TRP[j][1]  // column becomes row
              transpose_TRP[m][1] ← sparse_TRP[j][0]  // row becomes column
              transpose_TRP[m][2] ← sparse_TRP[j][2]  // value remains same
              m ← m + 1
          End If
      End For
20. End For

21. Display transpose_TRP

22. Stop


PROGRAM :
----------

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int **parr_TRP = NULL, **sparse_TRP = NULL, **transpose_TRP = NULL;
    int row_TRP, col_TRP, count_TRP = 0;

    cout << "Enter number of rows: ";
    cin >> row_TRP;
    cout << "Enter number of columns: ";
    cin >> col_TRP;

    // allocate parr_TRP matrix
    parr_TRP= new int*[row_TRP];
    if(parr_TRP==NULL) 
    { 
        cout<<"Memory not allocated"<<endl; 
        exit(0); 
    } 
    
    for(int i=0; i<row_TRP; i++) 
    { 
        parr_TRP[i]= new int[col_TRP]; 
        if(parr_TRP[i]==NULL) 
        { 
            cout<<"Memory not allocated.."<<endl;
             for(int j=0; j<i; j++) 
             { 
                delete[] parr_TRP[i];           
            } 
            delete[] parr_TRP; 
            exit(0); 
        } 
    }

    // fill matrix
    cout << "Enter " << row_TRP * col_TRP << " numbers (Enter most of 0): ";
    for (int i = 0; i < row_TRP; i++) {
        for (int j = 0; j < col_TRP; j++) {
            cin >> parr_TRP[i][j];
            if (parr_TRP[i][j] != 0) count_TRP++;
        }
    }

    // display original matrix
    cout << "Original matrix:\n";
    for (int i = 0; i < row_TRP; i++) 
    {
        for (int j = 0; j < col_TRP; j++) 
        {
            cout << parr_TRP[i][j] << " ";
        }
        cout << endl;
    }

    // allocate sparse_TRP matrix
    sparse_TRP = new int*[count_TRP + 1];
    if(sparse_TRP==NULL) 
    { 
        cout<<"Memory not allocated"<<endl;  
        exit(0); 
    } 
    for(int i=0; i<=count_TRP; i++) 
    { 
        sparse_TRP[i]= new int[3]; 
        if(sparse_TRP[i]==NULL) 
        { 
            cout<<"Memory not allocated.."<<endl; 
            for(int j=0; j<i; j++) 
            { 
                delete[] sparse_TRP[i]; 
            }
            
            delete[] sparse_TRP; 
            exit(0);
         } 
    }

    // fill sparse matrix
    int m = 1;
    sparse_TRP[0][0] = row_TRP;
    sparse_TRP[0][1] = col_TRP;
    sparse_TRP[0][2] = count_TRP;

    for (int i = 0; i < row_TRP; i++) {
        for (int j = 0; j < col_TRP; j++) {
            if (parr_TRP[i][j] != 0) {
                sparse_TRP[m][0] = i;
                sparse_TRP[m][1] = j;
                sparse_TRP[m][2] = parr_TRP[i][j];
                m++;
            }
        }
    }

    // print sparse matrix
    cout << "\nSparse matrix:\n";
    for (int i = 0; i <= count_TRP; i++) {
        for (int j = 0; j < 3; j++) {
            cout << sparse_TRP[i][j] << " ";
        }
        cout << endl;
    }

    // allocate transpose_TRP matrix
    transpose_TRP = new int*[count_TRP + 1];
    if( transpose_TRP==NULL) 
    { 
        cout<<"Memory not allocated"<<endl;  
        exit(0); 
    } 
    for(int i=0; i<=count_TRP; i++) 
    { 
         transpose_TRP[i]= new int[3]; 
        if( transpose_TRP[i]==NULL) 
        { 
            cout<<"Memory not allocated.."<<endl; 
            for(int j=0; j<i; j++) 
            { 
                delete[] transpose_TRP[i]; 
            }
            
            delete[]  transpose_TRP; 
            exit(0);
         } 
    }

    // fill transpose
    m = 1;
    transpose_TRP[0][0] = sparse_TRP[0][1]; 
    transpose_TRP[0][1] = sparse_TRP[0][0]; 
    transpose_TRP[0][2] = sparse_TRP[0][2];

    for (int i = 0; i < sparse_TRP[0][1]; i++) { 
        
        for (int j = 1; j <= count_TRP; j++) {
            if (sparse_TRP[j][1] == i) {
                transpose_TRP[m][0] = sparse_TRP[j][1];
                transpose_TRP[m][1] = sparse_TRP[j][0];
                transpose_TRP[m][2] = sparse_TRP[j][2];
                m++;
            }
        }
    }

    // print transpose
    cout << "\nTranspose of Sparse matrix:\n";
    for (int i = 0; i <= count_TRP; i++) {
        for (int j = 0; j < 3; j++) {
            cout << transpose_TRP[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

OUTPUT :
--------
C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS4.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter number of rows: 3
Enter number of columns: 4

Enter 12 numbers (Enter most of 0): 0 0 0 0 0 0 0 2 0 0 0 0 0

Original matrix:
0 0 0 0
0 0 0 2
0 0 0 0

Sparse matrix:
3 4 1
1 3 2

Transpose of Sparse matrix:
4 3 1
3 1 2