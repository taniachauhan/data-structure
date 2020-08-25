#include<iostream.h>
#include<conio.h>
#include<process.h>
class dll
 {
   public:
  struct node
   {
    int data;
    node *next;
    node *prev;
   }*head,*temp,*ptr,*s,*t;
   dll()
    {
      head=NULL;
     }
   void create(int x);
   void insert_at_end();
   void insert_at_begin();
   void insert_at_loc();
   void delete_at_begin();
   void delete_at_end();
   void delete_at_loc();
   void search();
   void count();
   void display();
  }t1;
  void main()
  {
   int ch1,n;
   char ch2;
   clrscr();
   do
    {
      cout<<"1.CREATE\n2.COUNT\n3.INSERT_AT_BEGIN\n4.INSERT_AT_LOC\n5.INSERT_AT_END\n6.DELETE_AT_BEGIN\n7.DELETE_AT_LOC\n8.DELETE_AT_END\n9.SEARCH\n10.DISPLATY\n11.EXIT\n";
      cout<<"enter your choice\n";
      cin>>ch1;
      switch(ch1)
      {
	  case 1: cout<<"enter the node";
		  cin>>n;
	      t1.create(n);
	      break;
	  case 2:
	      t1.count();
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
	      t1.display();
	      break;
	  case 11:
	      exit(0);
      }
    cout<<"\nwant to operate more?(y/n)";
    cin>>ch2;
    }while(ch2=='y');
  getch();
 }
   void dll::create(int value)
    {
	temp=new node;
	temp->data=value;
	temp->prev=NULL;
	temp->next=NULL;
     }
    void dll::display()
     {
      if(head==NULL)
	 {
	  cout<<"list is empty"<<endl;
	 }
       else
	{
	 cout<<"dispay the list"<<'\t';
	 ptr=head;
	 while(ptr!=NULL)
	  {
	   cout<<ptr->data<<'\t';
	   ptr=ptr->next;
	 }
	}
       }
     void dll::insert_at_begin()
     {
      if(head==NULL)
	 {
	  ptr=head;
	  }
	else
	{
	 ptr->next=head;
	 ptr->prev=NULL;
	 head=ptr;
     }

	}
   void dll::insert_at_end()
    {
	ptr->next=NULL;
	if(head==NULL)
	{
		ptr->prev=NULL;
		}
	else
	 {
		s=head;
		while(s->next!=NULL)
	    {
	      s=s->next;
	      ptr->prev=s;
	      s->next=ptr;
	    }
	   }
	}
     void dll::insert_at_loc(int a)

	{
	  int c=0;
	  t=head;
	  while(t!=NULL)
	   {
	    c=c+1;
	    if(c==a-1)
	    break;
	    t=t->next;
	  }
	    ptr->next=t->next;
	    ptr->prev=t;
	    t->next->prev=ptr;
	    t->next=ptr;
	  }
      void dll::delete_at_begin()
	   {
	    if(head==NULL)
	     {
	      cout<<"no node present";
	      }
	    else
	     {
	       ptr=head;
	       head->next=head;
	       head->prev=NULL;
	       delete ptr;
	      }

	   }
      void dll::delete_at_end()
	    {
	     if(head==NULL)
	      {
	       cout<<"no node present";
	       }
	    else
	     {
	      ptr=head;
	      while(ptr->next!=NULL)
	       {
		 ptr=ptr->next;
		}
		 if(head->next=NULL)
		  {
		      head==NULL;
		     }
		 else
		  {
		    ptr->prev->next=NULL;
		    delete ptr;
		   }
		 }
	       }
	void dll::delete_at_loc(int v)
	      {
	       if(head==NULL)
		{
		 cout<<"no node";
	       }
	       ptr=head;
		while(ptr!=NULL)
		 {
		  if(ptr->data=v)
		   {
		    ptr->prev->next=ptr->next;
		    ptr->next->prev=NULL;
		   delete ptr;
		  }
		 }
	       }
	 void dll::count()
		{
		 int c=0;
		 ptr=head;
		 while(ptr!=NULL)
		  {
		   ptr=ptr->next;
		    c++;
		   }
		  cout<<"no of nodes are"<<c;
		 }
	 void dll::search()
		{
		 int c=0,o;
		 cout<<"enter the node to searched";
		 cin>>o;
		 ptr=head;
		 while(ptr!=NULL)
		  {
		   c++;
		   if(ptr->data==o)
			    {
				    break;
			   }
			ptr=ptr->next;
		 }
		 if(c==0||ptr==NULL)
		 cout<<"node does not exist";
	       }
}