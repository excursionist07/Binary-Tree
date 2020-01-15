int evalTree(node* root)
{
  if(root==NULL)
   return 0;
  if(!root->left && !root->right)
   return stoi(root->data);
  int l=evalTree(root->left);
  int r=evalTree(root->right);
  if(root->data=="+")
   return l+r;
  else if(root->data=="-")
   return l-r;
  else if(root->data=="*")
   return l*r;
  else
   return l/r;
}
