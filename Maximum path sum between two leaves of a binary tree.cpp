int doit(Node* root,int &res)
{
 if(!root)
  return 0;
 if(!root->left && !root->right)
  return root->data;
 int L=doit(root->left,res);
 int R=doit(root->right,res);
 if(root->left && root->right)
 {
  res=max(res,L+R+root->data);
  return max(L,R)+root->data;
 }
 return (!root->left) ? R+root->data :L+root->data; // If any of the two children is empty, return root sum for root being on one side
      
}
int maxPathSum(Node* root)
{ 
  int res=INT_MIN;
  doit(root,res);
  return res;
}
