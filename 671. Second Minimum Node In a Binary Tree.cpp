/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
