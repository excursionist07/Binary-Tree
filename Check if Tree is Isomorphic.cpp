bool IsSymmetric(Node *root1,Node *root2)
{
 if(!root1 && !root2)
  return true;
 if(root1 && root2 && root1->data==root2->data)
  return IsSymmetric(root1->left,root2->right) &&  IsSymmetric(root1->right,root2->left);
 return false;
}

bool IsIdentical(Node *root1,Node *root2)
{
 if(!root1 && !root2)
  return true;
 if(root1 && root2 && root1->data==root2->data)
  return IsIdentical(root1->left,root2->left) &&  IsIdentical(root1->right,root2->right);
 return false;
}

bool isIsomorphic(Node *root1,Node *root2)
{
 return IsSymmetric(root1,root2) || IsIdentical(root1,root2);
}
