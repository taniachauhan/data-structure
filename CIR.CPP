#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define Null 0
class circular
{
  struct node
  {
    int data;
    struct node *next;
  }*head,*first,*tail,*temp;

  public:
  circular()
  {
    head=Null;
    tail=Null;

  }
  ~circular()
  {
  }

  void create();
  void display();
  void insert_at_beg();
  void insert_at_end();
  void insert_at_loc();
  void delete_at_beg();
  void delete_at_end();
  void delete_at_loc();
  void reverse();

}t1;
void main()
{
    int ch1;
    char ch2;
    clrscr();
    do
    {
      cout<<"1. Create \n";
      cout<<"2. Display \n";
      cout<<"3. Insert at beginning \n";
      cout<<"4. Insert at end \n";
      cout<<"5. Insert at a specific location \n";
      cout<<"6  Delete at beginning \n";
      cout<<"7. Delete at end \n";
      cout<<"8. Delete from a specific location \n";
      cout<<"9. Reverse \n";
      cout<<"10.  Exit \n";
      cout<<"Enter your choice: ";
      cin>>ch1;
      switch(ch1)
      {
      case 1:t1.create();
      break;
      case 2:t1.display();
      break;
      case 3:t1.insert_at_beg();
      break;
      case 4:t1.insert_at_end();
      break;
      case 5:t1.insert_at_loc();
      break;
      case 6:t1.delete_at_beg();
      break;
      case 7:t1.delete_at_end();
      break;
      case 8:t1.delete_at_loc();
      break;
      case 9:t1.reverse();
      break;
      case 10:exit(0);
      }
      cout<<"\n Do you want to operate more????(y/n): ";
      cin>>ch2;
      } while(ch2=='y'||ch2=='Y');
      getch();
 }
 void circular::create()
 {
    char ch='y' ;
    do{
    first=new node;
    cout<<"Enter the data item in the node: ";
    cin>>first->data;
    first->next=Null;
     if(head==Null)
    {
       head=first;
       tail=first;
     }
      else
      {

       tail->next=first;
       tail=first;
       tail->next=head;
      }

       cout<<"Do you want to insert more nodes(y/n) :  ";
       cin>>ch;
       }while(ch=='y');

      }


 void circular:: insert_at_beg()
  {
     first=new node;
     cout<<"Enter the data item in the node: ";
     cin>>first->data;
     first->next=head;
     tail->next=first;
     head=first;
     display();
  }

 void circular::insert_at_end()
  {
     first=new node;
     cout<<"Enter the data item in the node: ";
     cin>>first->data;
     tail->next=first;
     first->next=head;
     tail=first;
     display();
  }

 void circular::insert_at_loc()
  {
     int loc;
     first=new node;
     cout<<"Enter the data item in the node: ";
     cin>>first->data;
     cout<<"Enter the location";
     cin>>loc;
     temp=head;
     for(int i=0;i<loc-1;i++)
     temp=temp->next;
     first->next=temp->next;
     temp->next=first;
     display();
  }

 void circular::delete_at_beg()
  {
     temp=head;
     head=head->next;
     tail->next=head;
     temp->next=Null;
     display();

  }
 void circular::delete_at_end()
  {
     temp=head;
     while(temp->next!=tail)
     temp=temp->next;
     tail->next=Null;
     temp->next=head;
     tail=temp;
     display();
  }
 void circular::delete_at_loc()
  {
     int loc;
     cout<<"Enter the location ";
     cin>>loc;
     temp=head;
     for(int i=0;i<loc-1;i++)
     temp=temp->next;
     temp->next=temp->next->next;
     display();
  }


 void circular::reverse()
  {
     struct node *current,*prev ,*nextnode;
     current=tail->next;
     nextnode=current->next;
     if(tail==0)
      cout<<"circular list is empty";
     else
      {while(current!=tail)

     {
	prev=current;
	current=nextnode;
	nextnode=current->next;
	current->next=prev;
      }
      }
     display();
  }

 void circular::display()
   {

     struct node *temp;
     temp=head;
      if(temp==Null)
     {
       cout<<"circular list is empty";
     }
      else
     {
       cout<<"Elements of the list are: \n";
       while(temp->next!=head)
      {
	  cout<<temp->data;
	  cout<<"-->";
	  temp=temp->next;

      }
      cout<<temp->data;
     }
   }
