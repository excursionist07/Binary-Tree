

int maxPathUtil(Node *root,int &res)
{
 if(root==NULL)
  return 0;
 if(root->left==NULL && root->right==NULL)
  return root->data;
 int ls=maxPathUtil(root->left,res);
 int rs=maxPathUtil(root->right,res);
 if(root->left && root->right)
 {
  res=max(res,ls+rs+root->data);
  return max(ls,rs)+root->data;
 }
 return (root->left==NULL) ? rs+root->data : ls+root->data;
}
int maxPathSum(struct Node *root)
{
 int res=INT_MIN;
 maxPathUtil(root,res);
 return res;
}
