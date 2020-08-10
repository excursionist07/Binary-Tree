class Solution {
public:
    int doit(TreeNode* root,int val)
    {
     if(!root)
         return 0;
     val=val*10+root->val;
     if(!root->left && !root->right)
         return val;
     return doit(root->left,val)+doit(root->right,val);
    }
    int sumNumbers(TreeNode* root) 
    {
     return doit(root,0);    
    }
};
