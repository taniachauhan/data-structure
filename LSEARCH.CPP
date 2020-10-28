#include<iostream.h>
#include<conio.h>


int linear_search(int a[],int s,int ele)
 {
 	for(int i=0;i<s;i++)
 	 	if(a[i]==ele)
 	 	 	return i;
 	return -1;
}
 int main()
{
  	 int a[50],s,ele,t;
  	 cout<<"enter the  no of element in the array";
  	 cin>>s;
  	 for(int i=0;i<s;i++)
  	  {
  	  	cin>>a[i];
		}
	cout<<"the array is"<<endl;
	 for(int i=0;i<s;i++)
	  {
	  
	  	cout<<a[i];
	  }
	  cout<<"enter the element to be searched";
	  cin>>ele;
	  t=linear_search(a,s,ele);
	  if(t==-1)
	   {
	   	 cout<<"element not found in the array";
	   }
	  else
	   {
	   	 cout<<"element found at:"<<t; 
 		} 
 		return 0;
  }
