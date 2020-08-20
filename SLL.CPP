#include<conio.h>
#include<iostream.h>
#include<process.h>

class sll
{
 struct node
 {
  int data;
  struct node *next;
  } *head,*tail,*temp,*p,*s,*ptr;
  public:
   sll()
   {
     head=NULL;
     tail=NULL;
   }
   void create(int x);
   void traverse();
   void insert_at_end();
   void insert_at_begin();
   void insert_at_loc();
   void delete_at_begin();
   void delete_at_end();
   void delete_at_loc();
   void search();
   void reverse();
   void display();
  }t1;
  void main()
  {
   int ch1,n;
   char ch2;
   clrscr();
   do
    {
      cout<<"1.CREATE\n2.TRAVERSE\n3.INSERT_AT_BEGIN\n4.INSERT_AT_LOC\n5.INSERT_AT_END\n6.DELETE_AT_BEGIN\n7.DELETE_AT_LOC\n8.DELETE_AT_END\n9.SEARCH\n10.REVERSE\n11.DISPLATY\n12.EXIT\n";
      cout<<"enter your choice\n";
      cin>>ch1;
      switch(ch1)
      {
	  case 1: cout<<"enter the node";
		  cin>>n;
	      t1.create(n);
	      break;
	  case 2:
	      t1.traverse();
	      break;
	  case 3:
	      t1.insert_at_begin();
	      break;
	  case 4:
	      t1.insert_at_end();
	      break;
	  case 5:
	      t1.insert_at_loc();
	      break;
	  case 6:
	      t1.delete_at_begin();
	      break;
	  case 7:
	      t1.delete_at_end();
	      break;
	  case 8:
	      t1.delete_at_loc();
	      break;
	  case 9:
	      t1.search();
	      break;
	  case 10:
	      t1.reverse();
	      break;
	  case 11:
	      t1.display();
	      break;
	  case 12:
	      exit(0);
      }
    cout<<"\nwant to operate more?(y/n)";
    cin>>ch2;
    }while(ch2=='y');
  getch();
 }
 void sll::create(int value)
 {
 temp->data=value;
 temp->next=NULL;
 if(head==NULL)
 {
 head=temp;
 tail=temp;
 temp=NULL;
 }
 else
  {
  tail->next=temp;
  tail=temp;
  }
 }
 void sll::traverse()
 {
  cout<<"\nsll is:"<<endl;
  temp=head;
  while(temp!=NULL)
  {
   cout<<temp->data<<"->";
   temp=temp->next;
  }
  cout<<"NULL";
 }
 void sll::insert_at_begin()
 {
   int value;
   cout<<"enter the value to be inserted";
   cin>>value;
   if(head==NULL)
   {
    head=temp;
    head->next=NULL;
   }
   else
   {
    p=head;
    head=temp;
    head->next=p;
   }
   cout<<"element inserted at beginning"<<endl;
  }
  void sll::insert_at_end()
  {
   int value;
   cout<<"enter the value to be inserted:";
   cin>>value;
   s=head;
   while(s->next!=NULL)
   {
     s=s->next;
   }
   temp->next=NULL;
   s->next=temp;
   cout<<"element inserted at last"<<endl;
  }
  void sll::insert_at_loc()
  {
   int value,loc,count=0;
   cout<<"enter the value to be inserted:";
   cin>>value;
   temp=create(value);
   cout<<"enter the location at which node to be inserted:";
   cin>>loc;
   int i;
   s=head;
   while(s!=NULL)
   {
    s=s->next;
    count++;
   }
   if(loc==1)
   {
    if (head==NULL)
    {
     head=temp;
     head->next=NULL;
    }
    else
    {
      ptr=head;
      head=temp;
      head->next=ptr;
    }
   }
   else if(loc>1 && loc<=count)
   {
     s=head;
     for(i=1;i<loc;i++)
     {
      ptr=s;
      s=s->next;
     }
     ptr->next=temp;
     temp->next=s;
   }
   else
   {
    cout<<"location out of range"<<endl;
    }
   }
   void sll::delete_at_begin()
   {
    temp=head;
    head=head->next;
    if(head==tail)
    delete head
    else
    {
    temp=head;
    head=head->next;
    delete temp;
   }
   void sll::delete_at_end()
  {
    s=head;
    while(s->next!=NULL)
    {
     p=s;
     s=s->next;
    }
    tail=p;
    p->next=NULL;
    delete s;
   }
   void sll::delete_at_loc(int loc)
   {
    s=head;
    for(inti=1;i<loc;i++)
    {
     p=s;
     s=s->next;
    }
   p->next=s->next;
  }
  void sll::search(int element)
  {
   temp=head;
   if(temp->data==element)
   break;
   else (temp->data!=element)
   temp=temp->next;
  }
  void sll::reverse()
 {

   s=head;
   while(s!=head)
    {
    next=s->next;
    s->next=p->next;
    p=s;
    s=next;
    }
     head=p;
  }
  void sll::display()
  {

   if(head==NULL)
   {
    cout<<"the list is empty";
   }
   temp=head;
   cout<<"elements of list are:"<<endl;
   while (temp!=NULL)
   {
    cout<<temp->data<<"->";
    temp=temp->next;
   }
   cout<<"NULL"<<endl;
  }


