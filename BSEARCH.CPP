#include<iostream.h>
#include<conio.h>

int binary_search(int a[],int left,int right,int ele)
 {
 	int mid;
 	while(left<=right)
 	 {
 	 	mid=left+(right-1)/2;
 	 	if(a[mid]==ele)
 	 	 return mid;
 	 	else if(a[mid]<ele)
		  left=mid+1;
		else
		 right=mid-1;   
	  }
	  cout<<"element is not present";
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
	 for(i=0;i<s;i++)
	  {
	  
	  	cout<<a[i];
	  }
	  cout<<"enter the element to be searched";
	  cin>>ele;
	  t=binary_search(a,0,s-1,ele);
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
