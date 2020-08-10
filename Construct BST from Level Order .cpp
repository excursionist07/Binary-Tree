Node* level(Node* root,int x)
{
 if(!root)
  root=new Node(x);
 else if(x<root->data)
  root->left=level(root->left,x);
 else
  root->right=level(root->right,x);
 return root;
}
Node* constructBst(int arr[], int n)
{
 Node* root=NULL;
 for(int i=0;i<n;i++)
  root=level(root,arr[i]);
 return root;
	
}
