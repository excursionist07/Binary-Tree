class Solution {
public:
    int search(vector<int>& inorder,int start,int end,int x)
    {
     int i;
     for(i=start;i<=end;i++)
     {
      if(inorder[i]==x)
          break;
     }
     return i;
    }
    TreeNode* doit(vector<int>& inorder,vector<int>& postorder,int start,int end,int& idx)
    {
     if(start>end)
         return NULL;
     TreeNode* temp=new TreeNode(postorder[idx--]);
     if(start==end)
         return temp;
     int zz=search(inorder,start,end,temp->val);
     temp->right=doit(inorder,postorder,zz+1,end,idx);
     temp->left=doit(inorder,postorder,start,zz-1,idx);
     return temp;
     
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
     int n=inorder.size();
     int idx=n-1;
     return doit(inorder,postorder,0,n-1,idx);
    }
};
