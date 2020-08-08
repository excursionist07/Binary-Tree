int evalTree(node* root) 
{
  if(!root)
   return 0;
  if(!root->left && !root->right)
   return stoi(root->data);
  int l=evalTree(root->left);
  int r=evalTree(root->right);
  if(root->data=="+")
   return l+r;
  if(root->data=="-")
   return l-r;
  if(root->data=="*")
   return l*r;
  if(root->data=="/")
   return l/r;
  
}
