class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
     if(!root) //NO ROOT,GOW CAN ROOT TO LEAF SUM EQUALS sum
         return 0;
     else
     {
      bool ans=0;
      if(root->val==sum && !root->left && !root->right)
          return 1;
      sum-=root->val;
      if(root->left)
          ans=ans || hasPathSum(root->left,sum);
      if(root->right)
          ans=ans || hasPathSum(root->right,sum);
      return ans;
         
     }
    }
};
