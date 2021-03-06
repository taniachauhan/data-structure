 #include<iostream.h>
 #include<math.h>


 class HEAP
 {
  public:
  int a[50],s,t;
 void HEAP_dec_key(int a[],int b,int c)
  {
 	int g=floor(b/2);
 	a[b]=c;
	while(b>1&&a[g]>a[b])
 	{
 		swap(a[b],a[g]);
 		b=floor(b/2);
 		g=floor(b/2);
	 }
  }
 void insert(int a[],int x,int s)
  {
  	a[s]=-100;
  	HEAP_dec_key(a,s,x);
  }
  void minHEAPify(int a[],int ele,int s)
   {
   	 int len,ri,m;
	 len=2*ele;
	 ri=2*ele+1;
	 m=ele;
     if(len<=s&&a[ele]>a[len])
      {
	m=len;
      }
	if(ri<=s&&a[m]>a[ri])
	 {
		m=ri;
	 }
    if(m!=ele)
     {
	swap(a[m],a[ele]);
	minHEAPify(a,m,s);
     }
   }
   int minimumHEAP(int a[])
    {
      return a[1];
	}
 void extract_min_HEAP(int a[],int s)
  {
	if(s=0)
	 {
		cout<<"there is no element in the tree";
	 }
    else
     {
	a[1]=a[s];
	s--;
	minHEAPify(a,1,s);
    }
 }
  void buildHEAP(int a[],int s)
   {
	 int j=floor(s/2);
	 for(int i=j;i>=1;i--)
	  {
		minHEAPify(a,1,s);
	  }
   }
 };
int main()
 {
	int na,i,k,s;
	HEAP hp;
	int a[s];
	do
	 {
	  cout<<"\n 1.increase the key value \n 2.insert the element  \n 3.maximum value \n 4.extract maximum value \n "<<endl;
	  cout<<"enter the choice";
	  cin>>na;
	  switch(na)
	   {
	    case 1:
		    cout<<"enter the key value";
		    cin>>i;
		    cout<<"how much key is to be decreased";
		    cin>>k;
		    hp.HEAP_dec_key(a,i,k);
		    break;
	    case 2:
		    cout<<"enter the value to be inserted";
		    cin>>k;
		    s++;
		    hp.insert(a,k,s);
		    break;
	    case 3:
		    cout<<"minimum element in heap"<<endl;
		    hp.minimumHEAP(a);
		    cout<<endl;
		    break;
	    case 4:
		    cout<<"extract min element from heap"<<endl;
		    hp.extract_min_HEAP(a,s);
		    cout<<endl;
		    break;
	    default: cout<<"wrong choice"<<endl;
	     }
	      }while(na!=0);
	 }
