// 112. Path Sum

// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
class Solution {
public:
    void doit(TreeNode* root,int sum,int& cnt)
    {
     if(!root)
         return;
     if(!root->left && !root->right && root->val==sum)
     {
      cnt++;
      return;
     }
     doit(root->left,sum-root->val,cnt);
     doit(root->right,sum-root->val,cnt);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
    
     int cnt=0;
     doit(root,targetSum,cnt);
     return (cnt>=1);
    }
};

// 113. Path Sum II

// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

class Solution {
public:
    void doit(TreeNode* root,int sum,vector<int>vv,vector<vector<int>>& ans)
    {
     if(!root)
         return;
     vv.push_back(root->val);
     if(!root->left && !root->right && root->val==sum)
     {
      ans.push_back(vv);
      return;
     }
     doit(root->left,sum-root->val,vv,ans);
     doit(root->right,sum-root->val,vv,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
     vector<vector<int>>ans;
     vector<int>vv;
     doit(root,targetSum,vv,ans);
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
    void doit(TreeNode* root,int sum,int& total)
    {
     if(!root)
         return;
     sum=sum*10+root->val;
     if(!root->left && !root->right)
     {
      total+=sum;
      return;
     }
     doit(root->left,sum,total);
     doit(root->right,sum,total);
    }
    int sumNumbers(TreeNode* root) 
    {
     if(!root)
          return 0;
     int total=0;
     doit(root,0,total);
     return total;
    }
};

// Maximum path sum between two leaves of a binary tree

int doit(Node* root,int &res)
{
 if(!root)
  return 0;
 if(!root->left && !root->right)
  return root->data;
 int L=doit(root->left,res);
 int R=doit(root->right,res);
 if(root->left && root->right)
 {
  res=max(res,L+R+root->data);
  return max(L,R)+root->data;
 }
 return (!root->left) ? R+root->data :L+root->data; // If any of the two children is empty, return root sum for root being on one side
      
}
int maxPathSum(Node* root)
{ 
  int res=INT_MIN;
  doit(root,res);
  return res;
}

// Count Number of SubTrees having given Sum

int sum(Node* root)
{
 if(!root)
  return 0;
 return sum(root->left)+root->data+sum(root->right);
}
int countSubtreesWithSumX(Node* root, int X)
{
 if(!root)
  return 0;
 if(sum(root)==X)
  return 1+countSubtreesWithSumX(root->left,X)+countSubtreesWithSumX(root->right,X);
 else
   return countSubtreesWithSumX(root->left,X)+countSubtreesWithSumX(root->right,X);
}

// 617. Merge Two Binary Trees

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
      if(!t1)
          return t2;
      if(!t2)
          return t1;
      t1->val+=t2->val;
      t1->left= mergeTrees(t1->left,t2->left);
      t1->right= mergeTrees(t1->right,t2->right);
      return t1;
    }

