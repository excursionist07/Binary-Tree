int convert(Node* root)
{
 if(!root)
  return 0;
 int old=root->data;
 root->data=convert(root->left)+convert(root->right);
 return old+root->data;
 
}
void toSumTree(Node *node)
{
  if(!node)
   return;
  convert(node);
  
}

