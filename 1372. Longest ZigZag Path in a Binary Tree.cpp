/*
Complexity:

Time: O(n), it will visit all the nodes and each node once.
Space: O(h)
*/

class Solution {
public:
    void dfs(TreeNode* root,bool IsLeft,int steps,int& maxx)
    {
     if(!root)
         return;
     maxx=max(maxx,steps);
     if(IsLeft)
     {
      dfs(root->left,false,steps+1,maxx);// keep going from root to left
      dfs(root->right,true,1,maxx);// restart going from root to right
     }
     else
     {
      dfs(root->right,true,steps+1,maxx);// keep going from root to right
      dfs(root->left,false,1,maxx);// restart going from root to left
     }
    }
    int longestZigZag(TreeNode* root)
    {
     if(!root)
         return 0;
     if(root && !root->left && !root->right)
         return 0;
     int maxx=0;
     dfs(root,true,0,maxx);
     return maxx;
    }
    
};
