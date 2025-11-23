/*WAP to implement Bubble sort and Quick Sort on a 1D array of Student structure (contains student_name, student_roll_no, total_marks),
 with key as student_roll_no. And count the number of swap performed by each method.*/

 #include <iostream>
#include <cstring>
using namespace std;

int quick_swap_TRP = 0, bubble_swap_TRP = 0;

struct Student
{
    int roll_TRP;
    char name_TRP[100];
    int total_marks_TRP;
};

void Bubble_TRP(Student *st, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (st[j].roll_TRP > st[j + 1].roll_TRP)
            {
                Student temp_TRP = st[j];
                st[j] = st[j + 1];
                st[j + 1] = temp_TRP;
                bubble_swap_TRP++;
            }
        }
    }
}

int partition_TRP(Student *st, int lb, int ub)
{
    Student pivot_TRP = st[lb];
    int start_TRP = lb, end_TRP = ub;

    while (start_TRP < end_TRP)
    {
        while (st[start_TRP].roll_TRP <= pivot_TRP.roll_TRP && start_TRP < ub)
            start_TRP++;

        while (st[end_TRP].roll_TRP > pivot_TRP.roll_TRP && end_TRP > lb)
            end_TRP--;

        if (start_TRP < end_TRP)
        {
            Student temp_TRP = st[start_TRP];
            st[start_TRP] = st[end_TRP];
            st[end_TRP] = temp_TRP;
            quick_swap_TRP++;
        }
    }

    st[lb] = st[end_TRP];
    st[end_TRP] = pivot_TRP;
    quick_swap_TRP++;
    return end_TRP;
}

void Quick_TRP(Student *st, int lb, int ub)
{
    if (lb < ub)
    {
        int loc_TRP = partition_TRP(st, lb, ub);
        Quick_TRP(st, lb, loc_TRP - 1);
        Quick_TRP(st, loc_TRP + 1, ub);
    }
}

int main()
{
    Student *st = NULL, *stt = NULL;
    int num_TRP, OP_TRP;

    cout << "Enter number of student: ";
    cin >> num_TRP;

    st = new Student[num_TRP];
    stt = new Student[num_TRP];

    const char *names_TRP[] = {"Abir", "Aarav", "Isha", "Rohan", "Priya", "Vikas", "Neha", "Sahil", "Anaya", "Dev", "Kriti",
                               "Mira", "Kabir", "Tanvi", "Yash", "Riya", "Arjun", "Asha", "Nikhil", "Pooja", "Kunal", "Vishal", "Amir", "Sharukh", "Salman", "Mrunal", "Kirti"};
    const int N_NAMES_TRP = sizeof(names_TRP) / sizeof(names_TRP[0]);

    const int rollno_TRP[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    const int N_ROLL_TRP = sizeof(rollno_TRP) / sizeof(rollno_TRP[0]);

    const int total_m_TRP[] = {400, 390, 456, 178, 389, 467, 298, 498, 500, 498, 375, 785, 467, 563};
    const int N_TOTAL_TRP = sizeof(total_m_TRP) / sizeof(total_m_TRP[0]);

    // Fill n records using rand()
    for (int i = 0; i < num_TRP; i++)
    {
        st[i].roll_TRP = rollno_TRP[rand() % N_ROLL_TRP];
        strcpy(st[i].name_TRP, names_TRP[rand() % N_NAMES_TRP]);
        st[i].total_marks_TRP = total_m_TRP[rand() % N_TOTAL_TRP];

        stt[i].roll_TRP = st[i].roll_TRP;
        strcpy(stt[i].name_TRP, st[i].name_TRP);
        stt[i].total_marks_TRP = st[i].total_marks_TRP;
    }

    cout << "Records are:\n\n";
    for (int i = 0; i < num_TRP; i++)
    {
        cout << "ROLL NO: " << stt[i].roll_TRP << endl;
        cout << "NAME: " << stt[i].name_TRP << endl;
        cout << "TOTAL MARKS: " << stt[i].total_marks_TRP << endl;
        cout << "\n----------------------------------------------------------------------------\n";
    }

    cout << "----------------------------------------------------------------------------\n\n";

    do
    {
        cout << "\n\n1-Bubble sort\n2-Quick sort\n3-Exit\n";
        cout << "Enter correct choice: ";
        cin >> OP_TRP;

        switch (OP_TRP)
        {
        case 1:
            Bubble_TRP(st, num_TRP);
            cout << "Sorted Records are:\n";
            for (int i = 0; i < num_TRP; i++)
            {
                cout << "ROLL NO: " << st[i].roll_TRP << endl;
                cout << "NAME: " << st[i].name_TRP << endl;
                cout << "TOTAL MARKS: " << st[i].total_marks_TRP << endl;
                cout << "\n----------------------------------------------------------------------------\n";
            }
            cout << "No. of swaps: " << bubble_swap_TRP << endl;
            cout << "----------------------------------------------------------------------------\n\n";
            break;

        case 2:
            Quick_TRP(stt, 0, num_TRP - 1);
            cout << "Sorted Records are:\n";
            for (int i = 0; i < num_TRP; i++)
            {
                cout << "ROLL NO: " << stt[i].roll_TRP << endl;
                cout << "NAME: " << stt[i].name_TRP << endl;
                cout << "TOTAL MARKS: " << stt[i].total_marks_TRP << endl;
                cout << "\n----------------------------------------------------------------------------\n";
            }
            cout << "No. of swaps: " << quick_swap_TRP << endl;
            cout << "----------------------------------------------------------------------------\n\n";
            break;

        case 3:
            cout << "Enter any key to exit..\n";
            break;

        default:
            cout << "Enter correct choice\n";
        }
    } while (OP_TRP != 3);

    delete[] st;
    delete[] stt;

    return 0;
}




















