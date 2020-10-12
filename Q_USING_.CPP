#include<iostream.h>
#include<cstdlib.h>

class stack_dq
{   struct node
{
  public: int data;
	  node* next;
};
    private: node* head;
    public:
    int n1;
    stack_dq()
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
		{   cout<<"your entered queue is"<<endl;
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
    stack_dq d1;
    stack_dq d2;

   void enqueue()
    {
      cout<<"enter the data to enqueue"<<endl;
      cin>>x;
      d1.push(x);
    }
    void dequeue()
    {
	int x=0,y=0;
	while(!d1.isempty())
	{
	    x=d1.pop();
	    d2.push(x);
	}
	d2.pop();
	while(!d2.isempty())
	{
	    y=d2.pop();
	    d1.push(y);
	}
	if(!d1.isempty())
	{
	cout<<"dequeuing top element from the queue"<<endl;
	}
    }
    void display()
    {    int x=0,y=0;
	while(!d1.isempty())
	{
	    x=d1.pop();
	    d2.push(x);
	}
	d2.display();
	while(!d2.isempty())
	{
	    y=d2.pop();
	    d1.push(y);
	}
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