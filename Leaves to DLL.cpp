

Node *convertToDLL(Node *root,Node **head_ref)
{
 if(!root)
  return NULL;
 if(!root->left && !root->right)
 {
   if(*head_ref==NULL)
    *head_ref=root;
   else
   {
     root->right=*head_ref;
     (*head_ref)->left=root;
     *head_ref=root;

   }
   return NULL; // this statement detaches the leaf from the tree
 }

  root->right=convertToDLL(root->right,head_ref);

  root->left=convertToDLL(root->left,head_ref);

 //return *head_ref;
}
