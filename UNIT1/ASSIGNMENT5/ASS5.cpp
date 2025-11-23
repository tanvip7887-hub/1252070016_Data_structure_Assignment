//Develop a program to compute the fast transpose of a sparse matrix using its compact (triplet) representation efficiently.


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
    for (int i = 0; i < row_TRP; i++) {
        for (int j = 0; j < col_TRP; j++) {
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
