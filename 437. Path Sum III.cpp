/* Find the number of paths that sum to a given value.
   The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
*/

class Solution {
public:
    int ans=0;
    void doit(TreeNode* root,int sum)
    {
     if(!root)
         return;
     if(root->val==sum)
         ans++;
     doit(root->left,sum-root->val);
     doit(root->right,sum-root->val);
    }
    int pathSum(TreeNode* root, int sum)
    {
     if(root)
     {
      doit(root,sum);
      pathSum(root->left,sum);
      pathSum(root->right,sum);
     }
     return ans;
    }
};
