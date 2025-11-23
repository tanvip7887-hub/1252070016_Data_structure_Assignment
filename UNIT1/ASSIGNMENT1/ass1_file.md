
ASSIGNMENT 1 
===============

AIM : Implement basic string operations such as length calculation, copy, reverse, and concatenation using character single dimensional arrays without using built-in string library functions.

THEORY:
--------

1) String is a sequence of characters used to store text.

2) C++ supports strings using character arrays (char str[]) and the string class.

3) Character array strings end with a null character \0.

4) The string class in C++ provides many inbuilt functions for easy handling.

5) Common operations are length, copy, reverse, and concatenation.


PROGRAM:
---------

```cpp
#include <iostream>
using namespace std;

int stringLength_TRP(char *str_TRP) 
{
    int len_TRP = 0;
    while (str_TRP[len_TRP] != '\0') 
    len_TRP++;
    
    return len_TRP;
}

void stringCopy_TRP(char *str_TRP, char *str1_TRP) 
{
    int i_TRP = 0;
    while (str1_TRP[i_TRP] != '\0') 
    {
        str_TRP[i_TRP] = str1_TRP[i_TRP];
        i_TRP++;
    }
    str_TRP[i_TRP] = '\0';  
}

void stringReverse_TRP(char *str_TRP, char *str1_TRP) 
{
    int len = stringLength_TRP(str1_TRP);
    for (int i = 0; i < len; i++) 
    {
        str_TRP[i] = str1_TRP[len - 1 - i];
    }
    str_TRP[len] = '\0'; 
}

void stringConcat(char *str1_TRP, char *str2_TRP)
{
    int len1 = stringLength_TRP(str1_TRP);
    int i_TRP = 0;

    while (str2_TRP[i_TRP] != '\0')
    {
        str1_TRP[len1 + i_TRP] = str2_TRP[i_TRP];
        i_TRP++;
    }

    str1_TRP[len1 + i_TRP] = '\0'; // null terminate
}

int main() 
{
    int size1_TRP, size2_TRP;
    char *str1_TRP = NULL, *str2_TRP = NULL, *str_TRP = NULL;

    cout << "Enter size of first string: ";
    cin >> size1_TRP;
    cout << "Enter size of second string: ";
    cin >> size2_TRP;

    str1_TRP = new char[size1_TRP + size2_TRP]; 
    if(str1_TRP == NULL)
    {
       cout<<"Memory not allocated"<<endl;
       exit(0);
    }

    str2_TRP = new char[size2_TRP + 1];   
    if(str2_TRP == NULL)
    {
       cout<<"Memory not allocated"<<endl;
       exit(0);
    }

    str_TRP = new char[size1_TRP + 1];  
    if(str_TRP == NULL)
    {
       cout<<"Memory not allocated"<<endl;
       exit(0);
    }        

    cout << "Enter first string: ";
    cin >> str1_TRP;
    cout << "Enter second string: ";
    cin >> str2_TRP;

    cout << "\nLength of first string: " << stringLength_TRP(str1_TRP) << endl;
    cout << "Length of second string: " << stringLength_TRP(str2_TRP) << endl;

    stringCopy_TRP(str_TRP, str1_TRP);
    cout << "\nCopy string: " << str_TRP << endl;

    stringReverse_TRP(str_TRP, str1_TRP);
    cout << "\nReverse string: " << str_TRP << endl;

    stringConcat(str1_TRP, str2_TRP);
    cout << "\nConcatenation result: " << str1_TRP << endl;

    delete[] str1_TRP;
    delete[] str2_TRP;
    delete[] str_TRP;

    return 0;
}
```

OUTPUT :
---------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS1.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe
Enter size of first string: 3
Enter size of second string: 5
Enter first string: RAJ
Enter second string: KAMAL

Length of first string: 3
Length of second string: 5

Copy string: RAJ

Reverse string: JAR

Concatenation result: RAJKAMAL





















































