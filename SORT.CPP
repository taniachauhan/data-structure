 #include<iostream.h>
 #include<conio.h>

  class sort
   { 
    public:
    void insert(int a[],int s)
     {
      for(int i=0;i<s;i++)
        {
       	  cout<<"enter the element of array"<<i+1<<endl;
       	  cin>>a[i];
	}
    	
      }
    void selection_sort(int a[],int s)
    {
  	 int min,temp;
	for(int i=0;i<s-1;i++)
  	 {
  	 min=i;
  	 for(int k=i+1;k<s;k++)
  	  if(a[k]<a[min])
  	   min=k;
  	  temp=a[i];
  	  a[i]=a[min];
  	  a[min]=temp;
         }
     }
    void insertion_sort(int a[],int s)
    {
  	int m,k;
	for(int i=1;i<s;i++)
  	 {
  	 m=a[i];
  	 k=i;
  	 while(k>0 && a[k-1]>m)
  	   {
  	  	a[k]=a[k-1];
  	  	k--;
	   }
		a[k]=m;
          }

    }
    void bubble_sort(int a[],int s)
   {
  	int temp;
    for(int i=0;i<s;i++)
     {
       for(int k=0;k<s-i-1;k++)
	    {
	    	if(a[k]>a[k+1])
	    	 {
	    	 	temp=a[k];
	    	 	a[k]=a[k+1];
	    	 	a[k+1]=temp;
			 }
		 } 
	 }
  }
   void display(int a[],int s)
    {
	for(int i=0;i<s;i++)
  	  {
  	 	cout<<a[i];
	  }
    }
 };

int main()

{
	sort s;
	int na;
	int a[50],n;
	cout<<"enter the size of the array";
	cin>>n;
	a[n];
	s.insert(a,n);

	do

	{

		cout<<"\n\nMENU";

		cout<<"\n1. sort the array using selection sort";

		cout<<"\n2. Sort the array using insertion sort method";

		cout<<"\n3. Sort the array using bubble sort method";
		cout<<"enter the choice";
		cin>>na;
        switch(na)

		{

			case 1:s.selection_sort(a,n);
			       cout<<"sorted array is"<<endl;
			       s.display(a,n);
				   break;

			case 2:s.insertion_sort(a,n);
			       cout<<"sorted array is"<<endl;
			       s.display(a,n);
				   break;

			case 3:s.bubble_sort(a,n);
			       cout<<"sorted array is"<<endl;
				   s.display(a,n);	
				   break;

			default:cout<<"\nInvalid choice";

		}

	}while(na!=0);

}



