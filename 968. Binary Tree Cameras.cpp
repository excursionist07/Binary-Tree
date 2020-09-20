/*
If we set a camera at the leaf, the camera can cover the leaf and its parent.
If we set a camera at its parent, the camera can cover the leaf, its parent and its sibling.

We can see that the second plan is always better than the first.
Now we have only one option, set up camera to all leaves' parent.

Here is our greedy solution:

1. Set cameras on all leaves' parents, thenremove all covered nodes.
2. Repeat step 1 until all nodes are covered.

Apply a recusion function dfs.
Return 0 if it's a leaf.
Return 1 if it's a parent of a leaf, with a camera on this node.
Return -1 if it's coverd, without a camera on this node.
*/

class Solution {
public:
    
    int dfs(TreeNode* root,int& ans)
    {
     if(!root)
         return -1;
     int left=dfs(root->left,ans);
     int right=dfs(root->right,ans);
     if(left==0 || right==0)
     {
      ans++;
      return 1;
     }
     return (left==1 || right==1) ? -1 : 0;
    }
    int minCameraCover(TreeNode* root)
    {
     if(!root)
         return 0;
     if(root && !root->left && !root->right)
          return 1;
     int ans=0;
     int zz=dfs(root,ans);
     return ans+((zz==0) ? 1 : 0);
    }
};
