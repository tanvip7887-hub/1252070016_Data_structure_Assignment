
ASSIGNMENT 2
=============

AIM : Write a program to construct and verify a magic square of order 'n' (for both even & odd) such that all rows, columns, and diagonals sum to the same value.

THEORY :
---------

1) A magic square is an n × n matrix where the sum of rows, columns, and diagonals is the same.

2) This common sum is called the magic constant = n(n² + 1)/2.

3) For odd n, numbers are arranged using the Siamese method (up-right movement with wrapping).

4) For even n, special methods like doubly-even or singly-even are used.

5) Magic squares are useful in mathematics, problem-solving, and programming logic.


ALGORITHM :
------------

Algorithm Magic_Square_Odd_Order

1. Start

2. Input n_TRP → size of the magic square
   Repeat input if n_TRP <= 1 or n_TRP is even (odd-order only)

3. Allocate a 2D array parr_TRP[n_TRP][n_TRP]

4. Initialize all elements of parr_TRP to 0

5. Set starting position:
   row_TRP = 0
   col_TRP = n_TRP / 2  // middle column of first row

6. Initialize num_TRP = 1

7. While num_TRP <= n_TRP * n_TRP
   7.1 Place num_TRP in parr_TRP[row_TRP][col_TRP]
   7.2 Save previous position: p_row_TRP = row_TRP, p_col_TRP = col_TRP
   7.3 Move to next position:
       row_TRP = row_TRP - 1      // move up
       col_TRP = col_TRP + 1      // move right
   7.4 If row_TRP < 0 → row_TRP = n_TRP - 1  // wrap around top
   7.5 If col_TRP == n_TRP → col_TRP = 0     // wrap around right
   7.6 If parr_TRP[row_TRP][col_TRP] != 0
       row_TRP = p_row_TRP + 1
       col_TRP = p_col_TRP       // move down instead
   7.7 Increment num_TRP

8. Print the magic square parr_TRP

9. (Optional) Verify magic square:
   9.1 Calculate sum of each row, each column, and two diagonals
   9.2 If all sums equal → Magic square verified
   9.3 Else → Error

10. Free memory allocated for parr_TRP

11. Stop


PROGRAM :
----------

```cpp
#include<iostream>
using namespace std;

int main()
{
   int **parr_TRP=NULL;
   int row_TRP, col_TRP, n_TRP, p_row_TRP, p_col_TRP;
   int num_TRP=1;
   
   do
   {
    cout<<"Enter the size to store 2D array : ";
    cin>>n_TRP;
   }
   while(n_TRP<=1 || n_TRP%2==0);

    parr_TRP = new int*[n_TRP];
    if(parr_TRP==NULL)
    {
        cout<<" memory not allocated"<<endl;
        exit(0);
    }

    for (int i = 0; i < n_TRP; i++)
    {
       parr_TRP[i] = new int[n_TRP];

       if( parr_TRP[i] == NULL)
       {
         cout<<" memory not allocated"<<endl;
         for(int j=0; j<i; j++)
         {
             delete parr_TRP[j];
         }

         delete[] parr_TRP;
         exit(0);
       }
    }

   for(int j=0; j<n_TRP; j++)
   {
        for(int i=0; i<n_TRP; i++)
        {
            parr_TRP[i][j]=0;
        }
   }

   row_TRP=0;
   col_TRP=(int)n_TRP/2;

   while(num_TRP<=n_TRP*n_TRP)
   {
    parr_TRP[row_TRP][col_TRP]=num_TRP;

    p_row_TRP=row_TRP;
    p_col_TRP=col_TRP;

    row_TRP=row_TRP-1;
    col_TRP=col_TRP+1;

    if(row_TRP<0)
    {
        row_TRP=n_TRP-1;
    }

    if(col_TRP==n_TRP)
    {
        col_TRP=0;
    }

    if(parr_TRP[row_TRP][col_TRP]!=0)
     {
        row_TRP=p_row_TRP+1;
        col_TRP=p_col_TRP;
     }
     num_TRP++;
   }

    cout<<"Generated array element"<<endl;
    for(int j=0; j<n_TRP; j++)
    {
        for(int i=0; i<n_TRP; i++)
        {
            cout<<parr_TRP[j][i]<<" ";
        }
        printf("\n");
    }

   delete[] parr_TRP;
   parr_TRP=NULL;


    return 0;
}
```

OUTPUT :
---------
C:\Users\USER\OneDrive\Desktop\VS_DS_CPP> g++ ASS2.cpp
C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe
Enter the size to store 2D array : 3

Generated array element
8 1 6
3 5 7
4 9 2