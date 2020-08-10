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
    TreeNode* doit(vector<int>& preorder,vector<int>& inorder,int start,int end,int& idx)
    {
     if(start>end)
         return NULL;
     TreeNode* temp=new TreeNode(preorder[idx++]);
     if(start==end)
         return temp;
     int zz=search(inorder,start,end,temp->val);
     temp->left=doit(preorder,inorder,start,zz-1,idx);
     temp->right=doit(preorder,inorder,zz+1,end,idx);
     return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
     int n=preorder.size();
     int idx=0;
     return doit(preorder,inorder,0,n-1,idx);
     
    }
};
