int sum(Node* root)
{
 if(!root)
  return 0;
 return sum(root->left)+root->data+sum(root->right);
}
int countSubtreesWithSumX(Node* root, int X)
{
 if(!root)
  return 0;
 if(sum(root)==X)
  return 1+countSubtreesWithSumX(root->left,X)+countSubtreesWithSumX(root->right,X);
 else
   return countSubtreesWithSumX(root->left,X)+countSubtreesWithSumX(root->right,X);
}
