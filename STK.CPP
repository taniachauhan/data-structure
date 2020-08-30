#include<iostream.h>
#include<stdio.h>
#include<process.h>

struct node
{
  int data;
  node *next;
};


 class stack
  {
    node *top;

  public:

	stack()
	{
	  top = NULL;
	}
	void push()
	{
	  int value;
	  node *ptr;

	  cout<<"\nEnter the number to be pushed : ";
	  cin>>value;

	  ptr = new node;
	  ptr->data = value;
	  ptr->next = NULL;

	  if(top==NULL)
	    top=ptr;
	  else
	  {
	    ptr->next=top;
	    top=ptr;
	  }

	}


	void pop()
	{
	  node *temp;

	  if(top==NULL)
	    cout<<"\nStack is Empty";
	  else
	   {
	     cout<<"\nDeleted element is : "<<top->data;
	     temp=top;
	     top=top->next;
	   delete temp;
	   }
    }


    void clear()
    {
	node *ptr1 = top;

	while(ptr1 != NULL)
	{
	  cout<<ptr1->data<<"->";
	  node *temp = ptr1->next;
	    delete ptr1;
	    ptr1 = temp;

	}
	cout<<"NULL\n";
    }
};


int main()
{
    stack s;
    int ch;
    while(1)
    {
	cout<<"\n1.PUSH\n2.POP\n3.CLEAR\n";
	cin>>ch;
	switch(ch)
	{
	  case 1:
		  s.push();
		  break;
	  case 2:
		  s.pop();
		  break;
	  case 3:
		  s.clear();
		  exit(0);
	  default:
		  cout<<"\nEnter a valid choice";
	}
    }
	return 0;
}
