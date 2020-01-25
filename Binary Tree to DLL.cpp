void callit(Node *root,Node **head_ref)
{
 if(*head_ref==NULL)
  *head_ref=root;
  else
  {
    root->right=*head_ref;
    (*head_ref)->left=root;
    *head_ref=root;
  }
}

void reverseIn(Node *root,Node **head_ref)
{
 if(root==NULL)
  return;
 reverseIn(root->right,head_ref);
 callit(root,head_ref);
 reverseIn(root->left,head_ref);
}
void bToDLL(Node *root, Node **head_ref)
{
  if(root==NULL)
   return;
  reverseIn(root,head_ref);
}

