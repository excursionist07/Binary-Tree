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
    
   int maxpath(TreeNode* root,int &res)
   {
    if(!root)return 0;
    int l=maxpath(root->left,res);
    int r=maxpath(root->right,res);
    int xx=max(max(l,r)+root->val,root->val);// max(l,r)
    int yy=max(xx,l+r+root->val);// l+r
    res=max(res,yy);
    return xx;
   }
    
    int maxPathSum(TreeNode* root)
    {
     int res=INT_MIN;
     maxpath(root,res);
     return res;
    }
};
