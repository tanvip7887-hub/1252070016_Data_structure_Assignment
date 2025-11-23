
ASSIGNMENT 11
==============

AIM :   Implementation of Singly Linked List to Manage ‘Vertex Club’ Membership Records.
        The Department of Computer Engineering has a student club named ‘Vertex Club’ for second, third, and final year students. 
        The first member is the President and the last member is the Secretary. Write a C++ program to:

            ●	Add/delete members (including President/Secretary)
            ●	Count members
            ●	Display members
            ●	Concatenate two division lists
            Also implement: reverse, search by PRN, and sort by PRN operations.


THEORY :
--------

1) A Singly Linked List stores Vertex Club members as nodes containing PRN, name, and a pointer to the next member.

2) It allows easy insertion and deletion of President, Secretary, and general members without shifting elements.

3) The list can be traversed to display or count all members quickly.

4) Two division lists can be concatenated by linking the last node of one list to the first node of another.

5) Additional operations like reverse, search, and sort help manage the club records efficiently.


PROGRAM :
---------

```cpp
#include<iostream>
#include<string>
using namespace std;

typedef struct Vertex_Club
{
    int TRP_PRN;
    string TRP_name;
    struct Vertex_Club * next;
}vc;

//get new node
vc * TRP_getNode()
{
    vc * TRP_newNode = new vc;

    if(TRP_newNode == NULL)
    {
        cout<<"\nMemory not allocated.."<<endl;
        exit(0);
    }

    TRP_newNode -> next= NULL;
    return (TRP_newNode);
}

//create list or add members
vc * TRP_addMem( vc * TRP_head)
{
    vc * TRP_newNode = TRP_getNode();

    cout<<"\n\nEnter PRN number : ";
    cin>> TRP_newNode->TRP_PRN;

    cout<<"Enter name : ";
    cin>> TRP_newNode->TRP_name;

    if( TRP_head == NULL)
    {
        TRP_head = TRP_newNode;
    }
    else
    {
        TRP_newNode ->next = TRP_head;
        TRP_head = TRP_newNode;
    }

    return (TRP_head);
}

//display members
void TRP_displayMem( vc * TRP_head)
{
    if(TRP_head == NULL)
    {
        cout<<"\n\nList is empty..."<<endl<<endl;
    }
    else
    {
        vc * TRP_temp = TRP_head;

        cout<<"\n\nPresident ";

        while(TRP_temp != NULL)
        {
            cout<<"-> | "<<TRP_temp->TRP_PRN<<" | "<<TRP_temp->TRP_name<<" | ";
            TRP_temp = TRP_temp -> next;
        }

        cout<<" <- Secretary ";
        cout<<endl<<endl;
    }
}

//Delete members (delete first node)
vc * TRP_deleteMem( vc * TRP_head)
{
    if(TRP_head == NULL)
    {
        cout<<"\n\nList is empty..."<<endl<<endl;
    }
    else
    {
        vc * TRP_temp = TRP_head;

        cout<<"\nDeleted node"<<endl;
        cout<<" | "<<TRP_head->TRP_PRN<<" | "<<TRP_head->TRP_name<<" |"<<endl<<endl;

        TRP_head = TRP_head->next;
        delete TRP_temp;
    }

    return(TRP_head);
}

//Count members
int TRP_countMem ( vc * TRP_head)
{
    vc * TRP_temp = TRP_head;
    int TRP_count = 0;

    while ( TRP_temp != NULL)
    {
        TRP_count ++;
        TRP_temp = TRP_temp ->next;
    }

    return ( TRP_count );
}

//search by PRN
void TRP_searchMem(vc * TRP_head)
{
   if(TRP_head == NULL)
   {
    cout<<"\n\nList is empty.."<<endl<<endl;
   }
   else
   {
        int TRP_key;
        int TRP_found = 0;
        vc * TRP_temp = NULL;

        cout<<"\n\nEnter PRN number to search member: ";
        cin>>TRP_key;

        TRP_temp = TRP_head;

        while(TRP_temp != NULL )
        {
            if(TRP_temp->TRP_PRN == TRP_key)
            {
                TRP_found=1;
                break;
            }

            TRP_temp = TRP_temp -> next;
        }

        if( TRP_found == 0 )
        {
            cout<<"\n\nMember not in club"<<endl<<endl;
        }
        else
        {
            cout<<"\n\nMember in club : | "<<TRP_temp->TRP_PRN<<" | "<<TRP_temp->TRP_name<<" | "<<endl<<endl;
        }
   }

}

//sort member by PRN number (selection-like by swapping data)
vc * TRP_sortMem (vc * TRP_head )
{
    if(TRP_head==NULL)
    {
        cout<<"\n\nList is empty.."<<endl<<endl;
        return TRP_head;
    }

    for(vc* p = TRP_head; p != NULL; p = p->next)
    {
        for(vc* q = p->next; q != NULL; q = q->next)
        {
            if(p->TRP_PRN > q->TRP_PRN)
            {
                
                int tmpPRN = p->TRP_PRN;
                p->TRP_PRN = q->TRP_PRN;
                q->TRP_PRN = tmpPRN;
                
                string tmpName = p->TRP_name;
                p->TRP_name = q->TRP_name;
                q->TRP_name = tmpName;
            }
        }
    }

    cout<<"\n\nList sorted successfully.."<<endl<<endl;
    return TRP_head;
}

//reverse member list
vc * TRP_reverseMem( vc * TRP_head )
{
    if(TRP_head == NULL)
    {
        cout<<"\n\nList is empty.."<<endl<<endl;
        return TRP_head;
    }

    vc* curr = TRP_head;
    vc* prev = NULL;
    vc* nextt = NULL;

    while(curr != NULL)
    {
        nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
    }

    TRP_head = prev;
    return(TRP_head);
}

//Concatenate two division lists into a NEW list head3 (copies nodes)
// head1 and head2 remain unchanged
vc* TRP_concate(vc* head1, vc* head2)
{
    vc* head3 = NULL;
    vc* tail = NULL;

    // copy nodes from head1
    for(vc* p = head1; p != NULL; p = p->next)
    {
        vc* newNode = new vc;
        newNode->TRP_PRN = p->TRP_PRN;
        newNode->TRP_name = p->TRP_name;
        newNode->next = NULL;

        if(head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // copy nodes from head2 (append)
    for(vc* q = head2; q != NULL; q = q->next)
    {
        vc* newNode = new vc;
        newNode->TRP_PRN = q->TRP_PRN;
        newNode->TRP_name = q->TRP_name;
        newNode->next = NULL;

        if(head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if(head3 == NULL)
        cout<<"\n\nBoth lists are empty.."<<endl<<endl;
    else
        cout<<"\n\nLists concatenated into head3 (copy). head1 and head2 unchanged.\n\n";

    return head3;
}

//destroy list (pass pointer by reference so caller pointer can be set to NULL)
void TRP_destroyList(vc* &head)
{
    if(head == NULL)
    {
        cout<<"\n\nList is empty.."<<endl<<endl;
        return;
    }

    vc* temp;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
    cout<<"All nodes deleted.\n\n";
}

int main(void)
{
    int TRP_choice , TRP_n;
    vc* TRP_head1=NULL, *TRP_head2=NULL, *TRP_head3= NULL;

    do
    {
        cout<<"1- Add members \n2- Delete members \n3- Count members \n4- Display members \n5- Concatenate two division lists \n6- Reverse \n7- Search by PRN \n8- Sort by PRN \n9- Destroy list \n10- Exit"<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>TRP_choice;

        switch(TRP_choice)
        {
            case 1: //Add members
                    cout<<"\nEnter 1- For A division or 2- For B division: ";
                    cin>>TRP_n;

                    if(TRP_n==1)
                    {
                        TRP_head1= TRP_addMem(TRP_head1);
                    }
                    else
                    {
                        TRP_head2= TRP_addMem(TRP_head2);
                    }

                    break;

             case 2: // Delete members
                    cout<<"\nEnter 1- For A division or 2- For B division: ";
                    cin>>TRP_n;

                    if(TRP_n==1)
                    {
                      cout<<"\n\nDivision A "<<endl<<endl;
                      TRP_head1 =TRP_deleteMem(TRP_head1);
                    }
                    else
                    {
                       cout<<"\n\nDivision B "<<endl<<endl;
                       TRP_head2 = TRP_deleteMem(TRP_head2);
                    }
                    break;

             case 3: //Count members
                    {
                    int TRP_count;

                    cout<<"\nEnter 1- For A division or 2- For B division: ";
                    cin>>TRP_n;

                    if(TRP_n==1)
                    {
                        TRP_count = TRP_countMem(TRP_head1);
                        cout<<"\nNo. of members of Division A : "<<TRP_count<<endl<<endl;
                    }
                    else
                    {
                        TRP_count = TRP_countMem(TRP_head2);
                        cout<<"\nNo. of members of Division B : "<<TRP_count<<endl<<endl;
                    }
                    }
                    break;

             case 4: //Display members
                    cout<<"\nEnter 1- For A division or 2- For B division: ";
                    cin>>TRP_n;

                    if(TRP_n==1)
                    {
                      cout<<"\n\nDivision A "<<endl<<endl;
                      TRP_displayMem(TRP_head1);
                    }
                    else
                    {
                       cout<<"\n\nDivision B "<<endl<<endl;
                       TRP_displayMem(TRP_head2);
                    }
                    break;

             case 5: //Concatenate two division lists into head3 (copy)
                    TRP_head3 =  TRP_concate ( TRP_head1, TRP_head2);
                    cout<<"\n\nAfter Concatenate.. (displaying head3)\n\n";
                    TRP_displayMem(TRP_head3);
                    break;

             case 6: //Reverse
                    cout<<"\nEnter 1- For A division or 2- For B division: ";
                    cin>>TRP_n;

                    if(TRP_n==1)
                    {
                      cout<<"\n\nDivision A "<<endl<<endl;
                      TRP_head1 = TRP_reverseMem(TRP_head1);
                    }
                    else
                    {
                       cout<<"\n\nDivision B "<<endl<<endl;
                       TRP_head2 = TRP_reverseMem(TRP_head2);
                    }
                    break;

             case 7: //Search by PRN
                    cout<<"\nEnter 1- For A division or 2- For B division: ";
                    cin>>TRP_n;

                    if(TRP_n==1)
                    {
                      cout<<"\n\nSearch by PRN from Division A "<<endl;
                      TRP_searchMem(TRP_head1);
                    }
                    else
                    {
                       cout<<"\n\nSearch by PRN from Division B "<<endl;
                       TRP_searchMem(TRP_head2);
                    }
                    break;

             case 8: // Sort by PRN
                    cout<<"\nEnter 1- For A division or 2- For B division: ";
                    cin>>TRP_n;

                    if(TRP_n == 1)
                    {
                      cout<<"\n\nSort by PRN number (Division A) "<<endl;
                      TRP_head1= TRP_sortMem(TRP_head1);
                      TRP_displayMem(TRP_head1);
                    }
                    else
                    {
                       cout<<"\n\nSort by PRN number (Division B) "<<endl;
                        TRP_head2= TRP_sortMem(TRP_head2);
                        TRP_displayMem(TRP_head2);
                    }
                    break;

             case 9: //destroy list
                    cout<<"\nEnter 1- For A division or 2- For B division: ";
                    cin>>TRP_n;

                    if(TRP_n == 1)
                    {
                      TRP_destroyList(TRP_head1);
                    }
                    else
                    {
                      TRP_destroyList(TRP_head2);
                    }

                    break;


             case 10: //Exit
                    cout<<"Enter any key to exit.."<<endl;
                   
            
             default : cout<<"\nEnter correct choice "<<endl<<endl;
        }
    }
    while(TRP_choice != 10);

    return 0; 
}

```

OUTPUT :
---------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS11.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

1- Add members
2- Delete members
3- Count members
4- Display members
5- Concatenate two division lists
6- Reverse
7- Search by PRN
8- Sort by PRN
9- Destroy list
10- Exit

Enter your choice : 1

Enter 1- For A division or 2- For B division: 1


Enter PRN number : 12
Enter name : tanavi

1- Add members
2- Delete members
3- Count members
4- Display members
5- Concatenate two division lists
6- Reverse
7- Search by PRN
8- Sort by PRN
9- Destroy list
10- Exit

Enter your choice : 1

Enter 1- For A division or 2- For B division: 1


Enter PRN number : 15
Enter name : swarai

1- Add members
2- Delete members
3- Count members
4- Display members
5- Concatenate two division lists
6- Reverse
7- Search by PRN
8- Sort by PRN
9- Destroy list
10- Exit

Enter your choice : 1

Enter 1- For A division or 2- For B division: 2


Enter PRN number : 17
Enter name : jay

1- Add members
2- Delete members
3- Count members
4- Display members
5- Concatenate two division lists
6- Reverse
7- Search by PRN
8- Sort by PRN
9- Destroy list
10- Exit

Enter your choice : 1

Enter 1- For A division or 2- For B division: 2


Enter PRN number : 16
Enter name : devyani

1- Add members
2- Delete members
3- Count members
4- Display members
5- Concatenate two division lists
6- Reverse
7- Search by PRN
8- Sort by PRN
9- Destroy list
10- Exit

Enter your choice : 4

Enter 1- For A division or 2- For B division: 1


Division A

President -> | 15 | swarai | -> | 12 | tanavi |  <- Secretary

1- Add members
2- Delete members
3- Count members
4- Display members
5- Concatenate two division lists
6- Reverse
7- Search by PRN
8- Sort by PRN
9- Destroy list
10- Exit

Enter your choice : 4

Enter 1- For A division or 2- For B division: 2


Division B

President -> | 16 | devyani | -> | 17 | jay |  <- Secretary

1- Add members
2- Delete members
3- Count members
4- Display members
5- Concatenate two division lists
6- Reverse
7- Search by PRN
8- Sort by PRN
9- Destroy list
10- Exit

Enter your choice : 3

Enter 1- For A division or 2- For B division: 1

No. of members of Division A : 2

1- Add members
2- Delete members
3- Count members
4- Display members
5- Concatenate two division lists
6- Reverse
7- Search by PRN
8- Sort by PRN
9- Destroy list
10- Exit

Enter your choice : 3

Enter 1- For A division or 2- For B division: 2

No. of members of Division B : 2

1- Add members
2- Delete members
3- Count members
4- Display members
5- Concatenate two division lists
6- Reverse
7- Search by PRN
8- Sort by PRN
9- Destroy list
10- Exit

Enter your choice : 5


Lists concatenated into head3 (copy). head1 and head2 unchanged.

After Concatenate.. (displaying head3)

President -> | 15 | swarai | -> | 12 | tanavi | -> | 16 | devyani | -> | 17 | jay |  <- Secretary

1- Add members
2- Delete members
3- Count members
4- Display members
5- Concatenate two division lists
6- Reverse
7- Search by PRN
8- Sort by PRN
9- Destroy list
10- Exit

Enter your choice : 10
Enter any key to exit..

Enter correct choice


C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>