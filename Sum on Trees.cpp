// 112. Path Sum

// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
     if(!root) //NO ROOT,GOW CAN ROOT TO LEAF SUM EQUALS sum
         return 0;
     else
     {
      bool ans=0;
      if(root->val==sum && !root->left && !root->right)
          return 1;
      sum-=root->val;
      if(root->left)
          ans=ans || hasPathSum(root->left,sum);
      if(root->right)
          ans=ans || hasPathSum(root->right,sum);
      return ans;
         
     }
    }
};

// 113. Path Sum II

// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

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

// 437. Path Sum III

// Find the number of paths that sum to a given value.
// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes)

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

// 124. Binary Tree Maximum Path Sum

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

// 404. Sum of Left Leaves

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
     if(!root)
         return 0;
     else if(root->left && !root->left->left && !root->left->right)
         return root->left->val+sumOfLeftLeaves(root->right);
     return
         sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);

    }
};

// SumTree

int sum(Node* root)
{
 if(!root)
  return 0;
 return sum(root->left)+root->data+sum(root->right);
}
bool isSumTree(Node* root)
{
 if(!root || (!root->left && !root->right))
  return 1;
 int Lsum=sum(root->left);
 int Rsum=sum(root->right);
 if(Lsum+Rsum==root->data && isSumTree(root->left) && isSumTree(root->right))
  return true;
 else
  return false;
}

// Transform to Sum Tree

int convert(Node* root)
{
 if(!root)
  return 0;
 int old=root->data;
 root->data=convert(root->left)+convert(root->right);
 return old+root->data;
 
}
void toSumTree(Node *node)
{
  if(!node)
   return;
  convert(node);
  
}

// Sum of all the numbers that are formed from root to leaf paths

class Solution {
public:
    int doit(TreeNode* root,int val)
    {
     if(!root)
         return 0;
     val=val*10+root->val;
     if(!root->left && !root->right)
         return val;
     return doit(root->left,val)+doit(root->right,val);
    }
    int sumNumbers(TreeNode* root) 
    {
     return doit(root,0);    
    }
};

