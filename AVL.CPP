#include<iostream.h> 
 
  
class node  
{  
    public: 
    int key;  
    Node *left;
    Node *right;
    int ht; 
};
int ht(node *N)
{  
    if (N == NULL)  
        return 0;  
    return N->ht;  

}  
  int max(int x, int y)
{
    return (x > y)? x : y;
}
  Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->ht = 1;

    return(node);
}

Node *rightRotate(Node *b)
{
    Node *a = b->left;
    Node *T2 = a->right;
    a->right = b;
    b->left = T2;

    b->ht = max(ht(b->left),ht(b->right)) + 1;
    a->ht = max(ht(a->left),ht(a->right)) + 1;

    return a;
}

Node *leftRotate(Node *a)
{
    Node *b = a->right;
    Node *T2 = b->left;
    b->left = a;
    a->right = T2;

    a->ht = max(ht(a->left),ht(a->right)) + 1;
    b->ht = max(ht(b->left),ht(b->right)) + 1;

    return b;
}
  int getBalance(Node *N)
{
    if (N == NULL)
	return 0;
    return ht(N->left) - ht(N->right);
}
  Node* insert(Node* node, int key)
{
    if (node == NULL)
	return(newNode(key));

    if (key < node->key)
	node->left = insert(node->left, key);
    else if (key > node->key)
	node->right = insert(node->right, key);
    else
	return node;

    node->ht = 1 + max(ht(node->left),ht(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
	return rightRotate(node);

    if (balance < -1 && key > node->right->key)
	return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
	node->left = leftRotate(node->left);
	return rightRotate(node);
    }


    if (balance < -1 && key < node->right->key)
    {
	node->right = rightRotate(node->right);
	return leftRotate(node);
    }

    return node;
}
Node * minValueNode(Node* node)
{
    Node* current = node;
    while (current->left != NULL)
	current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
	return root;
    if ( key < root->key )
	root->left = deleteNode(root->left, key);
    else if( key > root->key )
	root->right = deleteNode(root->right, key);
    else
    {
	if( (root->left == NULL) ||  (root->right == NULL) )
	{
	    Node *temp = root->left?root->left:root->right;
	    if (temp == NULL)
	    {
		temp = root;
		root = NULL;
	    }
	    else
	    *root = *temp;
	     delete(temp);
	}
	else
	{
	    Node* temp = minValueNode(root->right);
	    root->key = temp->key;
	    root->right = deleteNode(root->right,temp->key);
	}
    }
    if (root == NULL)
    return root;
    root->ht = 1 + max(ht(root->left),ht(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
	return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0)
    {
	root->left = leftRotate(root->left);
	return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
	return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0)
    {
	root->right = rightRotate(root->right);
	return leftRotate(root);
    }

    return root;
}

void preorder(Node *root)
{
    if(root != NULL)
    {
	cout << root->key << " ";
	preorder(root->left);
	preorder(root->right);
    }
}
    int main()
     {
	Node av;
	Node *root=NULL;
	int choice,val,del;
	do
	 {
	  cout<<"\n 1.insertion  \n 2.deletion "<<endl;
	  cout<<"enter the choice";
	  cin>>choice;
	  switch(choice)
	   {
	    case 1:
		    cout<<"enter the value to be inserted";
		    cin>>val;
		    root=insert(root,val);
		    preorder(root);
		    break;
		case 2:
		     cout<<"enter the value to be deleted";
		     cin>>del;
		     deleteNode(root,del);
			 break;
	    default: cout<<"wrong choice"<<endl;
	     }
	      }while(choice!=0);
	 }