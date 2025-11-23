/*In Computer Engg. Dept. of VIT there are S.Y., T.Y., and B.Tech. students. Assume that all these students are on ground for a function. 
We need to identify a student of S.Y. div. (X) whose name is "XYZ" and roll no. is "17". Apply appropriate Searching method to identify 
the required student.*/	

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

