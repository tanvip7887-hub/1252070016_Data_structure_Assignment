/*Implement matrix multiplication and analyse its performance using row-major vs column-major order access patterns to understandnhow memory layout affects
 cache performance.*/

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
