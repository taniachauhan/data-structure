#include <iostream.h>
#include <process.h>


class bst
{
    struct node
     {
       public:
	      int data;
	      node* right;
	      node* left;
     };
    public:
	   node* root;

       bst()
	{
	  root=NULL;
	}
    void insert(int x)
     {
       node* ptr=new node;
       node* ptr1=new node;
       node* ptr2=new node;
       ptr->data=x;
       ptr->right=NULL;
       ptr->left=NULL;
       if(root==NULL)
	{
	  root=ptr;
	}
	else
	{
	    ptr1=root;
	    while(ptr1!=NULL)
	    {
		if(x<ptr1->data)
		{
		    ptr2=ptr1;
		    ptr1=ptr1->left;
		}
		else
		{
		    ptr2=ptr1;
		    ptr1=ptr1->right;
		}
	    }
	    if(x<ptr2->data)
	    {
	       ptr2->left=ptr;
	    }
	    else
	    {
	       ptr2->right=ptr;
	    }
	}
    }
    void recursive_inorder(node* ptr)
    {     if(ptr!=NULL)
	{
	    recursive_inorder(ptr->left);
	    cout<<ptr->data<<" ";
	    recursive_inorder(ptr->right);
	}
    }
    void recursive_preorder(node* ptr)
    {
	if(ptr!=NULL)
	{
	    cout<<ptr->data<<" ";
	    recursive_preorder(ptr->left);
	    recursive_preorder(ptr->right);
	}
    }
    void recursive_postorder(node* ptr)
    {   if(ptr!=NULL)
      {
	recursive_postorder(ptr->left);
	recursive_postorder(ptr->right);
	cout<<ptr->data<<" ";
      }
    }
    void iterative_preorder(node* ptr)
    {
      stack <node*> t;
      if(ptr!=NULL)
      {
	  t.push(ptr);
	  while(!t.empty())
	  {
	      ptr=t.top();
	      t.pop();
	      cout<<ptr->data<<" ";
	      if(ptr->right!=NULL)
	      {
		 t.push(ptr->right);
	      }
	      if(ptr->left!=NULL)
	      {
		 t.push(ptr->left);
	      }
	  }
      }
    }
    void iterative_Inorder(node* ptr)
    {
	stack <node*> t;
     while(ptr!=NULL||!t.empty())
     {
	while(ptr!=NULL)
	{
	   t.push(ptr);
	   ptr=ptr->left;
	}
	    ptr=t.top();
	    t.pop();
	    cout<<ptr->data<<" ";
	    ptr=ptr->right;
     }
    }
    void iterative_postorder(node* ptr)
    {
	stack <node*> t1;
	stack <node*> t2;
	t1.push(ptr);
	while(!t1.empty())
	{
	    ptr=t1.top();
	    t1.pop();
	    t2.push(ptr);
	    if(ptr->left!=NULL)
	    {
	    t1.push(ptr->left);
	    }
	    if(ptr->right!=NULL)
	    {
	    t1.push(ptr->right);
	    }
	}
	while(!t2.empty())
	{
	    cout<<t2.top()->data<<" ";
	    t2.pop();
	}
    }
    bool search(int aa);
    void search(int aa)
    {   int flag=0,i=0;
	node* ptr=new node;
	node* ptr3=new node;
	ptr=root;
	if(root==NULL)
	{
	    cout<<"bst is empty "<<endl;
	}
	else
	{
	    while(ptr!=NULL)
	    {
		if(aa<ptr->data)
		{
		    ptr3=ptr;
		    ptr=ptr->left;
		    i++;
		}
		else
		if(aa==ptr->data)
		{
		    cout<<"data entered "<<aa<<" present in bst at "<<i<< " level"<<endl;
		    flag=1;
		    return true;
		    break;
		}
		else
		{
		    ptr3=ptr;
		    ptr=ptr->right;
		    i++;
		}
	    }
	    if(flag==0)
	    {
	    cout<<"data entered "<<aa<<" not present in the bst "<<endl;
	    }
	    return false;
	}
    }
    void bfs(node* ptr)
    {
	queue <node*> s;
	s.push(ptr);
	node* aa=new node;
	while(!s.empty())
	{
	    aa=s.front();
	    cout<<aa->data<<" ";
	    s.pop();
	    if(aa->left!=NULL)
	    {
		s.push(aa->left);
	    }
	    if(aa->right!=NULL)
	    {
		s.push(aa->right);
	    }
	}
    }
    void mirror(node* ptr)
    {   node* temp=new node;
	if(ptr==NULL)
	{
	    return;
	}
	else
	{
	    mirror(ptr->left);
	    mirror(ptr->right);
	    temp=ptr->left;
	    ptr->left=ptr->right;
	    ptr->right=temp;
	}
    }
    void number(node* ptr)
    {   int i=0;
	int j=1;
       queue <node*> s;
	s.push(ptr);
	node* aa=new node;
	while(!s.empty())
	{
	    aa=s.front();
	    s.pop();
	    if(aa->left!=NULL)
	    {
		s.push(aa->left);
		j++;
	    }
	    if(aa->right!=NULL)
	    {
		s.push(aa->right);
		j++;
	    }
	    if(aa->right==NULL&&aa->left==NULL)
	    {
		i++;
	    }
	}
	cout<<"Total no. of nodes are: "<<j<<endl;
	cout<<"Total no. of leaves are: "<<i<<endl;
	cout<<"Total no. of non leaves are: "<<j-i<<endl;
    }
    void rep(int aa1,int aa2)
    {
      int flag=0;
	node* ptr=new node;
	node* ptr3=new node;
	ptr=root;
	if(root==NULL)
	{
	    cout<<"Bst is empty "<<endl;
	}
	else
	{
	    while(ptr!=NULL)
	    {
		if(aa1<ptr->data)
		{
		    ptr3=ptr;
		    ptr=ptr->left;
		}
		else
		if(aa1==ptr->data)
		{
		    insert(aa2);
		    flag=1;
		    break;
		}
		else
		{
		    ptr3=ptr;
		    ptr=ptr->right;
		}
	    }
	    if(flag==0)
	    {
	    cout<<"data entered"<<aa1<<"absent in the Bst"<<endl;
	    }
	}
    }
    int height(node* ptr)
    {    int h,z;
	if(ptr == NULL)
	     return 0;
	h=height(ptr->left);
	z=height(ptr->right);
	if(h>=z)
	{
	    return h+1;
	}
	else
	{
	    return z+1;
	}
    }
};
int main()
{   int x,aa,aa1,aa2;
    char ch='y';
    bst ob;
    do{
    cout<<"enter data in bst"<<endl;
    cin>>x;
    ob.insert(x);
    cout<<"continue(y/n)? "<<endl;
    cin>>ch;
    }while(ch=='y'||ch=='Y');
    int choice,flag=1;
 while(flag==1)
 {  cout<<"0. Exit"<<endl;
    cout<<"1. Recursive Inorder traversal"<<endl;
    cout<<"2. Recursive preorder traversal"<<endl;
    cout<<"3. Recursive postorder traversal"<<endl;
    cout<<"4. Searching an element"<<endl;
    cout<<"5. Iterative preorder traversal"<<endl;
    cout<<"6. Iterative Inorder traversal"<<endl;
    cout<<"7. Iterative postorder traversal"<<endl;
    cout<<"8. Level by level traversal (BFS)"<<endl;
    cout<<"9. Mirror image of tree"<<endl;
    cout<<"10. Count the non-leaf, leaf and total number of nodes"<<endl;
    cout<<"11. Search and replace"<<endl;
    cout<<"12. Height of tree"<<endl;
    cin>>choice;
    switch(choice)
    {
	case 0:
		flag=0;
		break;
	case 1:
		 cout<<"Inorder traversal is: "<<endl;
		 ob.recursive_inorder(ob.root);
		 cout<<endl;
		 break;
	case 2:
		cout<<"Preorder traversal is: "<<endl;
		ob.recursive_preorder(ob.root);
		cout<<endl;
		break;
	case 3:
		cout<<"postorder traversal is: "<<endl;
		ob.recursive_postorder(ob.root);
		cout<<endl;
		break;
	case 4:
		cout<<"Enter data to search "<<endl;
		cin>>n;
		ob.search(aa);
		break;
	case 5:
		cout<<"Iterative preorder traversal is: "<<endl;
		ob.iterative_preorder(ob.root);
		cout<<endl;
		break;
	 case 6:
		cout<<"Iterative Inorder traversal is: "<<endl;
		ob.iterative_Inorder(ob.root);
		cout<<endl;
		break;
	case 7:
		cout<<"Iterative postorder traversal is: "<<endl;
		ob.iterative_postorder(ob.root);
		cout<<endl;
		break;
	case 8:
		cout<<"level by level traversal (BFS) is: "<<endl;
		ob.bfs(ob.root);
		cout<<endl;
		break;
	case 9:
		cout<<"Mirror image of tree is: "<<endl;
		ob.mirror(ob.root);
		cout<<"BFS traversal of mirror image of tree is: ";
		ob.bfs(ob.root);
		cout<<endl;
		break;
	case 10:
		ob.number(ob.root);
		cout<<endl;
		break;
	case 11:
		cout<<"Enter data to search"<<endl;
		cin>>aa1;
		if(ob.search(aa1))
		{   cout<<"Enter data to replace"<<endl;
		    cin>>aa2;
		    ob.insert(aa2);
		}
		cout<<"Enter data to replace"<<endl;
		cin>>aa2;
		ob.rep(aa1,aa2);
		break;
	case 12:
	       cout<<"Height of tree is: "<<ob.height(ob.root)<<endl;
	       break;
	default: cout<<"invalid choice"<<endl;
    }
 }
    return 0;
}