int countLeaves(Node* root)
{
 if(root==NULL)
  return 0;
 else if(!root->left && !root->right)
  return 1;
 return countLeaves(root->left)+countLeaves(root->right);
}
