int sum(Node* root)
{
 if(!root)
  return 0;
 return sum(root->left)+root->data+sum(root->right);
}
bool isSumTree(Node* root)
{
 if(!root || (!root->left && !root->right))
  return 1;
 int Lsum=sum(root->left);
 int Rsum=sum(root->right);
 if(Lsum+Rsum==root->data && isSumTree(root->left) && isSumTree(root->right))
  return true;
 else
  return false;
}
