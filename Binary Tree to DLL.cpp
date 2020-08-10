void DLL(Node* root,Node* &head)
{
 if(!head)
  head=root;
 else
 {
  root->right=head;
  head->left=root;
  head=root;
 }
}
void doit(Node* root,Node* &head)
{
 if(!root)
  return;
 doit(root->right,head);
 DLL(root,head);
 doit(root->left,head);
}

Node * bToDLL(Node *root)
{
 if(!root)
  return NULL;
 Node* head=NULL;
 doit(root,head);
 return head;
}

