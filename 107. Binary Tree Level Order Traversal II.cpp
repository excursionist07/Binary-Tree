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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
     vector<vector<int>>ans;
     if(!root)
         return ans;
     queue<TreeNode*>q;
     q.push(root);
     while(!q.empty())
     {
      vector<int>vv;
      int zz=q.size();
      for(int i=0;i<zz;i++)
      {
       TreeNode* cur=q.front();
       q.pop();
       vv.push_back(cur->val);
       if(cur->left)
           q.push(cur->left);
       if(cur->right)
           q.push(cur->right);
      }
      ans.push_back(vv);
     }
     /*int n=ans.size();
     for(int i=0;i<n/2;i++)
     {
      vector<int>temp;
      temp=ans[i];
      ans[i]=ans[n-i-1];
      ans[n-i-1]=temp;

     }*/
     reverse(ans.begin(),ans.end());
     return ans;
    }
};
