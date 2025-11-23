/*
In the Second Year Computer Engineering class, there are two groups of students based on their favorite sports:
●	Set A includes students who like Cricket.
●	Set B includes students who like Football.
Write a C++ program to represent these two sets using linked lists and perform the following operations:
 a) Find and display the set of students who like both Cricket and Football.
 b) Find and display the set of students who like either Cricket or Football, but not both.
 c) Display the number of students who like neither Cricket nor Football.
*/

#include<iostream>
#include<string>
using namespace std;

typedef struct CS
{
   int roll;
   string name;
   struct CS *next;

}s;

s *getNode( )
{
    s * newNode = new CS;

    if(newNode == NULL)
    {
        cout<<"\nMemory not allocated..\n";
        exit(0);
    }

    newNode -> next =NULL;
    return newNode;

}

s *addStudent(s * student)
{
   s* newNode = getNode();
   int avail =0;

   cout<<"\nEnter roll no : ";
   cin>>newNode->roll;

   s * temp =NULL;
   temp =student;

   while(temp != NULL)
   {
     if(temp -> roll == newNode->roll)
     { 
        avail= 1;
        break;
     }
   }

   if( avail == 1)
   {
     cout<<"\ndupliacte entry\n\n";
    
   }
   else
   {
        cout<<"\nEnter name : ";
        cin>>newNode->name;

        if(student == NULL)
        {
            student = newNode;
        }
        else
        {
            s *temp = NULL;
            temp =student;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            
            temp->next = newNode;
            cout<<"\nStudent added successfully\n\n";
        }
    }
   
    return student;
}

bool isInList(s* head, int roll)
{
    s* temp = head;
    while(temp != NULL)
    {
        if(temp->roll == roll) return true;
        temp = temp->next;
    }
    return false;
}

void display( s* head)
{
   s * temp =head;

   while(temp != NULL)
   {
     cout<<"-> |"<<temp->roll<<"|"<<temp->name<<"|";
     temp =temp->next;
   }
}

int main(void)
{
    int ch,rn;
   
    s *student =NULL;
    s *cricket = NULL;
    s *football = NULL;

    do
    {
        cout<<endl<<endl;
        cout << "1. Add a student\n";
        cout << "2. Assign Cricket fan\n";
        cout << "3. Assign Football fan\n";
        cout << "4. Student in class\n";
        cout << "5. Display students who like Cricket\n";
        cout << "6. Display students who like Football \n";
        cout << "7. Display students who like both Cricket and Football\n";
        cout << "8. Display students who like either Cricket or Football but not both\n";
        cout << "9. Display number of students who not like anything\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1: 
                    {
                        student = addStudent(student);
                        break;
                    }

            case 2: 
                    {
                        cout<<"\nEnter rollno to add in cricket fan team : ";
                        cin>>rn;

                        s* temp = student;

                        while(temp!=NULL)
                        {
                            if(rn == temp->roll)
                            {
                                break;
                            }
                            temp = temp->next;
                        }

                        if(temp == NULL)
                        {
                            cout<<"\nStudent with roll no "<<rn<<" not in class"<<endl<<endl;
                        }
                        else
                        {
                            s * newNode = getNode();
                            newNode -> roll = temp -> roll;
                            newNode -> name = temp -> name;

                            if(cricket == NULL)
                            {
                                cricket = newNode;
                            }
                            else
                            {
                                s* temp2 = cricket; 
                                while(temp2 -> next != NULL)
                                {
                                    temp2 = temp2->next;
                                }
                                temp2 -> next = newNode;
                            }
                            cout<<"\nStudent added successfully\n\n";
                        }
                        break;
                    }

            case 3:
                    {
                        cout<<"\nEnter rollno to add in football fan team : ";
                        cin>>rn;

                        s* temp = student;

                        while(temp!=NULL)
                        {
                            if(rn == temp->roll)
                            {
                                break;
                            }
                            temp = temp->next;
                        }

                        if(temp == NULL)
                        {
                            cout<<"\nStudent with roll no "<<rn<<" not in class"<<endl<<endl;
                        }
                        else
                        {
                            s * newNode = getNode();
                            newNode -> roll = temp -> roll;
                            newNode -> name = temp -> name;

                            if(football == NULL)
                            {
                                football= newNode;
                            }
                            else
                            {
                                s* temp2 = football; 
                                while(temp2 -> next != NULL)
                                {
                                    temp2 = temp2->next;
                                }
                                temp2 -> next = newNode;
                            }
                            cout<<"\nStudent added successfully\n\n";
                        }
                        break;
                    }

            case 4: 
                    if(student== NULL)
                    {
                        cout<<"\nNo one in class\n\n";
                    }
                    else
                    {
                        cout<<"\nThe students in class\n\n";
                        display(student);
                    }
                    break;

            case 5: 
                    {
                        if(cricket == NULL)
                        {
                            cout<<"\nNo one like cricket\n\n";
                        }
                        else
                        {
                            cout<<"\nThe students who like Cricket\n\n";
                            display(cricket);
                        }
                        break;
                    }

            case 6: 
                    {
                        if(football == NULL)
                        {
                            cout<<"\nNo one like football\n\n";
                        }
                        else
                        {
                            cout<<"\nThe students who like football\n";
                            display(football);
                        }
                        break;
                    }

            case 7:
                    { 
                        s* temp = cricket;
                        cout << "Students who like both Cricket and Football:\n\n";

                        while(temp != NULL)
                        {
                            if(isInList(football, temp->roll)) 
                                cout << "|" << temp->roll << "|" << temp->name << "|\n";

                            temp = temp->next;
                        }
                        break;
                    }

            case 8: 
                    { 
                        cout << "Students who like either Cricket or Football but not both:\n\n";
                        s* temp = cricket;
                        while(temp != NULL)
                        {
                            if(!isInList(football, temp->roll))
                                cout << "|" << temp->roll << "|" << temp->name << "|\n";
                            temp = temp->next;
                        }
                        temp = football;
                        while(temp != NULL)
                        {
                            if(!isInList(cricket, temp->roll))
                                cout << "|" << temp->roll << "|" << temp->name << "|\n";
                            temp = temp->next;
                        }
                        break; 
                    }

            case 9: 
                    { 
                        cout << "Students who not like anything:\n\n";
                        s* temp = student;
                        while(temp != NULL)
                        {
                            if(!isInList(cricket, temp->roll) && !isInList(football, temp->roll))
                                cout << "|" << temp->roll << "|" << temp->name << "|\n";
                            temp = temp->next;
                        }
                    
                        break; 
                    }

            case 0: 
                    cout<<"\nEnter any key to exit\n";
                    break;

            default: 
                    cout<<"\nInvalid choice\n";
        }

    }
    while(ch != 0);

    return 0;
}













































