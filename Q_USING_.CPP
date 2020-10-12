#include<iostream.h>
#include<cstdlib.h>

class stack_eq
{   struct node
{
  public: int data;
	  node* next;
};
    private: node* head;
    public:
    int n1;
    stack_eq()
    {
     head=NULL;
    }
   void push(int x)
   {
		 node* temp=new node;
		 temp->data=x;
		 temp->next=NULL;
		 if(head==NULL)
		 {
		     head=temp;
		     temp=NULL;
		 }
		 else
		 {
		     temp->next=head;
		     head=temp;
		 }
   }
   int pop()
   {
       if(head==NULL)
	       {
		   cout<<"queue is empty"<<endl;
		   return NULL;
	       }
	       else
	       {
		   node* ptr=new node;
		   ptr=head;
		   head=ptr->next;
		   return ptr->data;
	       }
   }
     void display()
	     {
		node* ptr=new node;
		ptr=head;
		if(head==NULL)
		{
		    cout<<"queue is empty"<<endl;
		}
		else
		{   cout<<"entered queue is"<<endl;
		while(ptr!=NULL)
		{
		    cout<<ptr->data<<" ";
		    ptr=ptr->next;
		}
		}
		cout<<endl;
	     }
	     bool isempty()
	     {
		 if(head==NULL)
		 {
		     return true;
		 }
		 else
		 {
		     return false;
		 }
	     }
};
class queue_arr
{    public:
    int x=0,y=0,z=0;
    stack_eq e1;
    stack_eq e2;

   void enqueue()
    {
      cout<<"enter the data to enqueue"<<endl;
      cin>>x;
      while(!e1.isempty())
      {
	  y=e1.pop();
	  e2.push(y);
      }
      e1.push(x);
      while(!e2.isempty())
      {
	 z=e2.pop();
	 e1.push(z);
      }
    }
    void dequeue()
    {    e1.pop();
	if(!e1.isempty())
	{
	cout<<"dequeuing top element from the queue"<<endl;
	}
    }
    void display()
    {
	e1.display();
    }


};
int main()
{   int n=0;
   queue_arr obj;
    int choice,flag=1;

 while(flag==1)
 {  cout<<"press 0 for exit"<<endl;
    cout<<"press 1 for displaying queue"<<endl;
    cout<<"press 2 for enqueuing"<<endl;
    cout<<"press 3 for dequeuing"<<endl;
    cin>>choice;
    switch(choice)
    {
	case 0: flag=0;
		break;
	case 1:
		obj.display();
		break;
	case 2:

		obj.enqueue();
		break;
	case 3:
		obj.dequeue();
		break;
	default: cout<<"invalid input"<<endl;

    }
 }
    return 0;
}