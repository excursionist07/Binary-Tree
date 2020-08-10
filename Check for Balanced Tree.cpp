class Solution {
public:
    int height(TreeNode* root)
    {
     if(!root)
         return -1;
     else
     {
      int LH=height(root->left);
      int RH=height(root->right);
      return 1+max(LH,RH);
     }
    }
    bool isBalanced(TreeNode* root)
    {
      if(!root)
          return 1;
      int L=height(root->left);
      int R=height(root->right);
      
      if(abs(L-R)<=1 && isBalanced(root->left) && isBalanced(root->right))
          return 1;
     return 0;
    }
};
