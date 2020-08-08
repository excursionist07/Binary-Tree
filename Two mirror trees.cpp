Node* makemirror(Node* root)
{
 if(!root)
  return NULL;
 if(root->left)
  makemirror(root->left);
 if(root->right)
  makemirror(root->right);
 Node* temp=root->left;
 root->left=root->right;
 root->right=temp;
 return root;
}
bool IsIdentical(Node* a,Node* b)
{
 if(!a && !b)
  return true;
 if(a && b && a->data==b->data)
  return IsIdentical(a->left,b->left) && IsIdentical(a->right,b->right);
 return false;
}
int areMirror(Node* a, Node* b) 
{
  if(!a && !b)
   return 1;
  makemirror(a);
 return IsIdentical(a,b);
}
