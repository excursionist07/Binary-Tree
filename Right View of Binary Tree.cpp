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
