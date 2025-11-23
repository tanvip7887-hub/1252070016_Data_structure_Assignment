/*The ticket reservation system for Galaxy Multiplex is to be implemented using a C++ program. The multiplex has 8 rows, with 8 seats 
in each row. A doubly circular linked list will be used to track the availability of seats in each row.Initially, assume that some seats 
are randomly booked. An array will store head pointers for each row’s linked list.The system should support the following operations:
a) Display the current list of available seats.
b) Book one or more seats as per customer request.
c) Cancel an existing booking when requested.	
*/

#include<iostream>
using namespace std;

typedef struct TRP_Node
{
    int seatNo;
    bool booked;
    TRP_Node* next;
    TRP_Node* prev;
} t;

t * getNode(int seatNo)
{
    t* newNode = new TRP_Node;
    if(newNode == NULL)
    {
        cout<<"\n\nMemory not allocated\n\n";
        exit(0);
    }
    newNode->seatNo = seatNo;
    newNode->booked = false;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

t* createList()
{
    t * head =NULL;
    t* prevnode =NULL;

     for(int i=1 ; i<=8; i++)
     {
        t * newNode = getNode(i);
       
        if(head==NULL)
        {
            head = newNode;
            newNode->prev= newNode;
            newNode->next= newNode;
            prevnode = head;
        }
        else
        {
           prevnode->next = newNode;
           newNode->prev= prevnode;
           newNode->next= head;
           head->prev=newNode;
           prevnode = newNode;
        }
     }
     return(head);
}

void *bookSeat( t * head[])
{
    int count =0;
    t * temp =NULL;
    temp =NULL;
    int rowno, seat;

        cout<<"\nEnter row number: ";
        cin>>rowno;

        cout<<"\nEnter seat number: ";
        cin>>seat;

        temp =head[rowno-1];
        count=0;

        while(count != seat-1)
        {
           temp =temp->next;
           count++;
        }

        if(temp->booked)
        {
            cout<<"\nSeat booked already. book another one \n\n";
        }
        else
        {
            temp->booked= true;
            cout<<"\nYour seat booked successfully\n\n";
        }  

}


void cancelSeat(t* head[]) {
    int rowno, seat;

    cout << "\nEnter Row No: ";
    cin >> rowno;

    cout << "Enter Seat No: ";
    cin >> seat;

    t* temp = head[rowno - 1]; 

    while (temp != nullptr) {
        if (temp->seatNo == seat) 
        {
            if (temp->booked == 1) 
            {
                temp->booked = 0;
                cout << "\nSeat cancelled successfully!\n";
            } 
            else 
            {
                cout << "\nSeat is not booked!\n";
            }
            return;
        }
        temp = temp->next;
    }

    cout << "\nSeat not found!\n";
}


void display(t * head)
{
    t *temp = head;
    do
    {
       cout<<"->|"<<temp->seatNo<<"|"<<temp->booked<<"|";
       temp = temp->next;
    }
    while(temp != head);

    cout<<endl<<endl;
}

int main()
{
    t *rows[8];

    int ch;
    
    for (int i = 0; i < 8; i++)
        rows[i] = createList();

    do
    {
       cout<<"\n\n1-Display available seat\n2-Book seat\n3-Cancel seat\n4-Exit\n\n";
       cout<<"Enter choice: ";
       cin>>ch;

       switch(ch)
       {
        case 1: //Display available seat 
                cout<<"\n\n1-Booked 0-available\n\n";
                for(int i=0 ; i<8 ;i++)
                {
                    cout<<"\n\nRow "<<i+1;
                    display(rows[i]);
                }
                break;

        case 2: //Book seat
                bookSeat(rows);

                break;

        case 3: //Cancel seat
                cancelSeat(rows);
                break;

        case 4: cout<<"\n\nEnter any key to exit\n\n";
                break;

        default : cout<<"\n\nInvalid choice\n\n";
       }

    }
    while(ch!=4);



    return 0;
}



























