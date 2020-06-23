 int ans=0;
    void dfs(TreeNode* root,int sum)
    {
     if(!root)
         return;
     if(root->val==sum)ans++;
     dfs(root->left,sum-root->val);
     dfs(root->right,sum-root->val);
    }

    int pathSum(TreeNode* root, int sum)
    {
      if(root)
      {
       dfs(root,sum);
       pathSum(root->left,sum);
       pathSum(root->right,sum);
      }
      return ans;
    }
