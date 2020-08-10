Node* doit(Node* root,Node* &head)
{
 if(!root)
  return NULL;
 if(!root->left && !root->right)
 {
  if(!head)
   head=root;
  else
   {
    root->right=head;
    head->left=root;
    head=root;
   }
   return NULL;// this statement detaches the leaf from the tree
 }
 root->right=doit(root->right,head);
 root->left=doit(root->left,head);
}
Node * convertToDLL(Node *root)
{
  if(!root)
   return NULL;
  Node* head=NULL;
  doit(root,head);
  return head;
}
