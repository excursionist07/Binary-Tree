int maxpath(TreeNode* root,int &res)
   {
    if(!root)return 0;
    int l=maxpath(root->left,res);
    int r=maxpath(root->right,res);
    int xx=max(max(l,r)+root->val,root->val);
    int yy=max(xx,l+r+root->val);
    res=max(res,yy);
    return xx;
   }

    int maxPathSum(TreeNode* root)
    {
     int res=INT_MIN;
     maxpath(root,res);
     return res;
    }
