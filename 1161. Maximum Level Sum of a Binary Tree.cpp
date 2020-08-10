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
