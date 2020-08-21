// 107. Binary Tree Level Order Traversal II

// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

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

// 1161. Maximum Level Sum of a Binary Tree

class Solution {
public:
    int maxLevelSum(TreeNode* root)
    {
     if(!root)
          return 0;
     queue<TreeNode*>q;
     q.push(root);
     int maxx=INT_MIN,ans,level=0;
     while(!q.empty())
     {
      int zz=q.size();
      int sum=0;
      level++;
      for(int i=0;i<zz;i++)
      {
       TreeNode* cur=q.front();
       q.pop();
       sum+=cur->val;
       if(cur->left)
           q.push(cur->left);
       if(cur->right)
           q.push(cur->right);

      }
      if(sum>maxx)
      {
       maxx=sum;
       ans=level;
      }
     }
     return ans;
    }
};

// 515. Find Largest Value in Each Tree Row

class Solution {
public:
    vector<int> largestValues(TreeNode* root)
    {
     vector<int>ans;
     if(!root)
         return ans;
     queue<TreeNode*>q;
     q.push(root);
     while(!q.empty())
     {
      int maxx=INT_MIN;
      int zz=q.size();
      for(int i=0;i<zz;i++)
      {
       TreeNode* cur=q.front();
       q.pop();
       maxx=max(maxx,cur->val);
       if(cur->left)
           q.push(cur->left);
       if(cur->right)
           q.push(cur->right);
      }
      ans.push_back(maxx);
     }
     return ans;
    }
};

// 