// 98. Validate Binary Search Tree

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

// 671. Second Minimum Node In a Binary Tree

class Solution {
public:
    long minn1=1e11,minn2=1e11;
    void doit(TreeNode* root)
    {
     if(!root)
         return;
     if(minn1>=root->val)
         minn1=root->val;
     else if(minn2>root->val)
         minn2=root->val;

     doit(root->left);
     doit(root->right);
    }
    int findSecondMinimumValue(TreeNode* root)
    {
     if(!root)
         return -1;
     doit(root);
     return (minn2==1e11) ? -1 : minn2;
    }
};
