class Solution {
public:
    bool doit(TreeNode* root,long long int minn,long long int maxx)
    {
     if(!root)
         return 1;
     if(root->val<=minn || root->val>=maxx)
         return 0;
     return doit(root->left,minn,root->val) && doit(root->right,root->val,maxx);
    }
    bool isValidBST(TreeNode* root) 
    {
     if(!root)
         return true;
     return doit(root,-1e18,1e18);
    }
};
