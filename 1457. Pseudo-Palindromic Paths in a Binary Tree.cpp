class Solution {
public:
    void dfs(TreeNode* root,vector<int>vv,vector<vector<int>>&ans) // O(n^2)
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
     int cnt=__builtin_popcount(xx);// count number of set bits in cnt
     if(!root->left && !root->right)
     {
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
