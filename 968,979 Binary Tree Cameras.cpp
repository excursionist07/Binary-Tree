// 1457. Pseudo-Palindromic Paths in a Binary Tree

// o(n^2)

class Solution {
public:
    void dfs(TreeNode* root,vector<int>vv,vector<vector<int>>&ans) // --> print all paths from root to leaves
    {
     if(!root)
         return;
     vv.push_back(root->val);
     if(!root->left && !root->right)
     {
       ans.push_back(vv);
       return;
     }
     dfs(root->left,vv,ans);
     dfs(root->right,vv,ans);

    }
    
    int pseudoPalindromicPaths (TreeNode* root) 
    {
     if(!root)
         return 0;
     vector<int>vv;
     vector<vector<int>>ans;
     dfs(root,vv,ans);
     int cnt=0;
     for(int i=0;i<ans.size();i++)
     {
      unordered_map<int,int>mp;
      for(int j=0;j<ans[i].size();j++)
      {
       mp[ans[i][j]]++;
      }
      if(ans[i].size() & 1) // odd size
      {
       int odd=0;
       for(auto xx:mp) //--> since nodes value are 1-9,it's complexity is irrelevant
       {
        if(xx.second & 1)
            odd++;
       }
       if(odd==1)
           cnt++;
      }
      else             // even size
      {
       int even=0;
       for(auto xx:mp)
       {
        if(xx.second & 1)
            even++;
       }
       if(even==0)
           cnt++;
      }
     }
     return cnt;
    }
};

// o(n) time and 0(1) space

class Solution {
public:
    void dfs(TreeNode* root,int xx,int& ans) // O(n) && 0(1)
    {
     if(!root)
         return;
     xx=xx^(1<<root->val); // if a particular number occurence is even times then it will be nullified 
     if(!root->left && !root->right)
     {
      int cnt=__builtin_popcount(xx);// count number of set bits in cnt
      if(cnt<=1) // cnt==0--> for even sized palindrome and cnt==1 for odd sized palaindrome,for a odd sized palindrome only one number occurence should be odd and for even all number occurence should be even
          ans++;
      return;
     }
     dfs(root->left,xx,ans);
     dfs(root->right,xx,ans);

    }
    
    int pseudoPalindromicPaths (TreeNode* root) 
    {
     if(!root)
         return 0;
     int ans=0;
     dfs(root,0,ans);
     return ans;
    }
};

// 968. Binary Tree Cameras

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

Time Complexity: O(N), where N is the number of nodes in the tree.
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
     return (left==1 || right==1) ? -1 : 0; // if either of them is 1 ,so it covers the upper node so return -1
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



// 979. Distribute Coins in Binary Tree

/*
At each node, some candies will come from the left and goes to the right or comes from the right and goes to left.
https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal---> for better understanding
Time Complexity: O(N), where N is the number of nodes in the tree.
*/

class Solution {
public:
    int dfs(TreeNode* root,int& ans)
    {
     if(!root)
         return 0;
     int left=dfs(root->left,ans);
     int right=dfs(root->right,ans);
     ans+=(abs(left)+abs(right));
     return root->val+left+right-1; // -1 for keeping one coin for itself
    }
    int distributeCoins(TreeNode* root) 
    {
     if(!root)
         return 0;
     if(root && !root->left && !root->right)
         return 0;
     int ans=0;
     dfs(root,ans);
     return ans;
     
    }
};

