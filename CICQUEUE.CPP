#include<iostream.h>
#include<stdio.h>
#include<process.h>

template <class T, int size = 7>

class Queue
{
private:
	int first, last;
	T arr[size];


public:
	T item, r;
	Queue()
	{
	  first=last=-1;
	    for (int i = 0; i < size; ++i)
	      {
		arr[i]=-989;
	      }
	}
	void enqueue(T);
	T dequeue();
	bool isFull()
	{
	  return first == 0 && last == size -1 || first == last+1;
	}
	bool isEmpty()
	{
	  return first==-1;
	}
	void show()
	{
	  for (int i = 0; i < size; ++i)
	   {
	     cout<<arr[i]<<"->";
	   }
	cout<<"NULL\n-989 represents empty spaces in Queue";
	}
};


template <class T, int size>
void Queue<T,size>::enqueue(T el)
{
	if(!isFull())
	{
	  if(last == size-1 || last == -1)
	    {
	      arr[0] = el;
	      last = 0;

	       if(first == -1)
		first = 0;
	    }
	      else
		{
		  arr[++last] = el;
		}
	}
	else
	  cout<<"\nQueue is Full";
}

template <class T,int size>
T Queue<T,size>::dequeue()
{
	T temp;
	temp = arr[first];
	arr[first] = -989;
	if (first == last)
	  first = last = -1;
	else if(first == size-1)
	{
	  first = 0;
	}
	else
	  first++;
	return temp;

}

int main()
{
    Queue <int>q;
    int ch;
    while(1)
    {
	cout<<"\n1.PUSH\n2.POP\n3.DISPLAY & EXIT\n";
	cin>>ch;
	switch(ch)
	{
	  case 1:
		  cout<<"\nEnter the value to be pushed : ";
		  cin>>q.item;
		  q.enqueue(q.item);
		  break;
	  case 2:
		  q.r = q.dequeue();
		  cout<<"\nValue popped out is : "<<q.r;
		  break;
	  case 3:
		  q.show();
		  exit(0);
	  default:
		  cout<<"\nEnter a valid choice";
	}
    }
	return 0;
}
