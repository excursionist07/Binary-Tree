 void flatten(TreeNode* root)
    {
      if(!root)return ;
      flatten(root->left);
      flatten(root->right);
      if(root->left)
      {
       TreeNode *rr=root->right;
       root->right=root->left;
       root->left=NULL;
       while(root->right)root=root->right;
       root->right=rr;

      }
