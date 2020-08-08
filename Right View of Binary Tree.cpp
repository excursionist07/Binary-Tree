//RECURSIVE

class Solution {
public:
    void doit(TreeNode* root,int level,int* maxlevel,vector<int>& ans)
    {
     if(!root)
         return;
     if(level>*maxlevel)
     {
      ans.push_back(root->val);
      *maxlevel=level;
     }
     doit(root->right,level+1,maxlevel,ans);
     doit(root->left,level+1,maxlevel,ans);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
     vector<int>ans;
     if(!root)  
         return ans;
     int maxlevel=0;
     doit(root,1,&maxlevel,ans);
     return ans;
     
    }
};

//ITERATIVE

 queue<TreeNode*>q;// since right view is last element of each row
    q.push(root);
    while(!q.empty())
    {
     int zz=q.size();
     bool ff=1;
     for(int i=0;i<zz;i++)
     {
      TreeNode* cur=q.front();
      q.pop();
      if(ff)
         ans.push_back(cur->val),ff=0;
      if(cur->right)
          q.push(cur->right);
      if(cur->left)
          q.push(cur->left);
     }
    }
     return ans;
     
