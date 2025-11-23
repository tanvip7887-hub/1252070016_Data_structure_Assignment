/*Write a program to construct and verify a magic square of order 'n' (for both even & odd) such that all rows, columns, and diagonals sum to the same value.*/

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