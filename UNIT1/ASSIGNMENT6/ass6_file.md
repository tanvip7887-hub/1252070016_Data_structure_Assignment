
ASSIGNMENT 6
=============

AIM : In Computer Engg. Dept. of VIT there are S.Y., T.Y., and B.Tech. students. Assume that all these students are on ground for a function. 
We need to identify a student of S.Y. div. (X) whose name is "XYZ" and roll no. is "17". Apply appropriate Searching method to identify 
the required student.

THEORY :
---------

1) In this problem we have to use linear serach to find out student.

2) Linear search checks each element one by one in the list.

3) If the element matches the key, it is found; otherwise, the search ends after the last element.

4) Here, we search student by roll_no, name of student and display student record if found otherwise not. 



ALGORITHM :
------------


Algorithm Search_Student

1.  Start
2.  Input n → number of students
3.  For i ← 0 to n-1 do
4.      Input student details:
        - roll_TRP
        - name_TRP
        - city_TRP
        - className_TRP
        - branch_TRP
        - div_TRP
        - age_TRP
5.      Store details in array Students[i]
6.  End For

7.  Input target details:
       - target_name ← "XYZ"
       - target_roll ← 17
       - target_class ← "S.Y."
       - target_div ← "X"

8.  found ← false
9.  For i ← 0 to n-1 do
10.     If Students[i].name_TRP = target_name AND
           Students[i].roll_TRP = target_roll AND
           Students[i].className_TRP = target_class AND
           Students[i].div_TRP = target_div then
11.         Print "Record Found" and display student details
12.         found ← true
13.         Exit loop
14.     End If
15. End For

16. If found = false then
17.     Print "Record Not Found"
18. End If

19. Stop


PROGRAM :
-----------


```CPP
#include <iostream>
#include <cstring> //<string> in c
using namespace std;

#define NAME_LEN_TRP   32
#define CITY_LEN_TRP    32
#define CLASS_LEN_TRP   8
#define BRANCH_LEN_TRP  12
#define DIV_LEN_TRP    4

typedef struct Student
{
    int  roll_TRP;
    char name_TRP[NAME_LEN_TRP];
    char city_TRP[CITY_LEN_TRP];
    char className_TRP[CLASS_LEN_TRP];
    char branch_TRP[BRANCH_LEN_TRP];
    char div_TRP[DIV_LEN_TRP];
    int  age_TRP;
}Student;

int main()
{
    Student* st = NULL;
    int n_TRP;
    int i_TRP;
    int choice_TRP;

    cout << "Enter the Number of Student Records you want to create : ";
    cin >> n_TRP;

    st = new Student[n_TRP];
    if (st == NULL)
    {
        cout << "Memory allocation failed.\n";
        exit(-1);
    }

    const char* names_TRP[] = { "Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil","Anaya","Dev","Kriti",
        "Mira","Kabir","Tanvi","Yash","Riya","Arjun","Asha","Nikhil","Pooja","Kunal", "Vishal","Amir","Sharukh","Salman","Mrunal","Kirti" };
    const int N_NAMES_TRP = sizeof(names_TRP) / sizeof(names_TRP[0]);

    const char* cities_TRP[] = { "Amravati","Akola","Nagar","Pune","Mumbai","Nashik","Nagpur","Aurangabad","Thane","Satara","Solapur","Kolhapur","Nanded" };
    const int N_CITIES_TRP = sizeof(cities_TRP) / sizeof(cities_TRP[0]);

    const char* classes_TRP[] = { "FE","SE","TE","BE" };
    const int N_CLASSES_TRP = sizeof(classes_TRP) / sizeof(classes_TRP[0]);

    const char* branches_TRP[] = { "COMP","IT","AIDS","ENTC","MECH","CIVIL", "AIML", "IOT"};
    const int N_BRANCHES_TRP = sizeof(branches_TRP) / sizeof(branches_TRP[0]);

    const char* divs_TRP[] = { "A","B","C","D" };
    const int N_DIVS_TRP = sizeof(divs_TRP) / sizeof(divs_TRP[0]);

    for (i_TRP = 0; i_TRP < n_TRP; i_TRP++)
    {
        st[i_TRP].roll_TRP = i_TRP + 1;
        strcpy(st[i_TRP].name_TRP, names_TRP[rand() % N_NAMES_TRP]);
        strcpy(st[i_TRP].city_TRP, cities_TRP[rand() % N_CITIES_TRP]);
        strcpy(st[i_TRP].className_TRP, classes_TRP[rand() % N_CLASSES_TRP]);
        strcpy(st[i_TRP].branch_TRP, branches_TRP[rand() % N_BRANCHES_TRP]);
        strcpy(st[i_TRP].div_TRP, divs_TRP[rand() % N_DIVS_TRP]);
        st[i_TRP].age_TRP = 18 + (rand() % 5);
    }

    cout << "\n------------------------------  All Student Records (" << n_TRP << ") -----------------------------\n";
    for (i_TRP= 0; i_TRP< n_TRP; i_TRP++)
    {
        cout<<"Student "<<i_TRP+1<<endl;
        cout << "Roll No: " << st[i_TRP].roll_TRP<<endl;
        cout << "Name: " << st[i_TRP].name_TRP<<endl;
        cout<< "City: " << st[i_TRP].city_TRP<<endl;
        cout<< "Class Name: " << st[i_TRP].className_TRP<<endl;
        cout<< "Branch: " << st[i_TRP].branch_TRP<<endl;
        cout<< "Division: " << st[i_TRP].div_TRP<<endl;
        cout<< "Age: " << st[i_TRP].age_TRP <<endl<<endl;
    }

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1) Search by Roll\n";
        cout << "2) Search by Name\n";
        cout << "3) Print All Records\n";
        cout << "0) Exit\n";
        cout << "Enter choice: ";
        cin >> choice_TRP;

        switch (choice_TRP)
        {
            case 1:
            {
                int targetRollNo_TRP;
                cout << "Enter the Roll No: ";
                cin >> targetRollNo_TRP;

                bool found = false;
                for (i_TRP= 0; i_TRP < n_TRP; i_TRP++)
                {
                    if (st[i_TRP].roll_TRP == targetRollNo_TRP)
                    {
                        cout << "\nRECORD FOUND : "<<endl;
                        cout << "Roll No: " << st[i_TRP].roll_TRP<<endl;
                        cout << "Name: " << st[i_TRP].name_TRP<<endl;
                        cout<< "City: " << st[i_TRP].city_TRP<<endl;
                        cout<< "Class Name: " << st[i_TRP].className_TRP<<endl;
                        cout<< "Branch: " << st[i_TRP].branch_TRP<<endl;
                        cout<< "Division: " << st[i_TRP].div_TRP<<endl;
                        cout<< "Age: " << st[i_TRP].age_TRP <<endl<<endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "\nRECORD NOT FOUND.. \n\n";
                break;
            }
            case 2:
            {
                char targetName_TRP[NAME_LEN_TRP];
                cout << "Enter EXACT name to search (case-sensitive): ";
                cin >> targetName_TRP;

                int matches_TRP = 0;
                for (i_TRP = 0; i_TRP< n_TRP; i_TRP++)
                {
                    if (strcmp(st[i_TRP].name_TRP, targetName_TRP) == 0)
                    {
                        cout << "\nRECORD FOUND : "<<endl;
                        cout << "Roll No: " << st[i_TRP].roll_TRP<<endl;
                        cout << "Name: " << st[i_TRP].name_TRP<<endl;
                        cout<< "City: " << st[i_TRP].city_TRP<<endl;
                        cout<< "Class Name: " << st[i_TRP].className_TRP<<endl;
                        cout<< "Branch: " << st[i_TRP].branch_TRP<<endl;
                        cout<< "Division: " << st[i_TRP].div_TRP<<endl;
                        cout<< "Age: " << st[i_TRP].age_TRP <<endl<<endl;
                        matches_TRP++;
                    }
                }
                if (matches_TRP == 0)
                    cout << "\nRECORD NOT FOUND.. \n\n";
                break;
            }

            case 3:
            {
                cout << "\n=== All Student Records (" << n_TRP << ") ===\n";
                for (i_TRP= 0; i_TRP< n_TRP; i_TRP++)
                {
                    cout<<"Student "<<i_TRP+1<<endl;
                    cout << "Roll No: " << st[i_TRP].roll_TRP<<endl;
                    cout << "Name: " << st[i_TRP].name_TRP<<endl;
                    cout<< "City: " << st[i_TRP].city_TRP<<endl;
                    cout<< "Class Name: " << st[i_TRP].className_TRP<<endl;
                    cout<< "Branch: " << st[i_TRP].branch_TRP<<endl;
                    cout<< "Division: " << st[i_TRP].div_TRP<<endl;
                    cout<< "Age: " << st[i_TRP].age_TRP <<endl<<endl;
                }
                break;
            }

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice...\n";
                break;
        }

    } while (choice_TRP != 0);

    delete[] st;
    return 0;
}
```


OUTPUT :
---------


C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS6.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter the Number of Student Records you want to create : 4

------------------------------  All Student Records (4) -----------------------------

Student 1
Roll No: 1
Name: Yash
City: Aurangabad
Class Name: TE
Branch: MECH
Division: B
Age: 22

Student 2
Roll No: 2
Name: Rohan
City: Mumbai
Class Name: TE
Branch: COMP
Division: B
Age: 18

Student 3
Roll No: 3
Name: Sahil
City: Nashik
Class Name: SE
Branch: ENTC
Division: D
Age: 20

Student 4
Roll No: 4
Name: Vishal
City: Nagar
Class Name: BE
Branch: MECH
Division: C
Age: 21


--- MENU ---
1) Search by Roll
2) Search by Name
3) Print All Records
0) Exit
Enter choice: 1
Enter the Roll No: 3

RECORD FOUND :

Roll No: 3
Name: Sahil
City: Nashik
Class Name: SE
Branch: ENTC
Division: D
Age: 20


--- MENU ---
1) Search by Roll
2) Search by Name
3) Print All Records
0) Exit
Enter choice: 2
Enter EXACT name to search (case-sensitive): sahil

RECORD NOT FOUND..


--- MENU ---
1) Search by Roll
2) Search by Name
3) Print All Records
0) Exit
Enter choice:
2
Enter EXACT name to search (case-sensitive): Sahil

RECORD FOUND :

Roll No: 3
Name: Sahil
City: Nashik
Class Name: SE
Branch: ENTC
Division: D
Age: 20


LINEAR SEARCH ( DRY RUN ) :
----------------------------


![alt text](image.png)






