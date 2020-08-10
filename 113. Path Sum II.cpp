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
    void doit(TreeNode* root,int sum,vector<int>vv,vector<vector<int>>&ans)
    {
     if(!root)
         return;
     vv.push_back(root->val);
     if(!root->left && !root->right && root->val==sum)
         ans.push_back(vv);
     doit(root->left,sum-root->val,vv,ans);
     doit(root->right,sum-root->val,vv,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
     vector<int>vv;
     vector<vector<int>>ans;
     if(!root)
         return ans;
     doit(root,sum,vv,ans);
     return ans;
    }
};
