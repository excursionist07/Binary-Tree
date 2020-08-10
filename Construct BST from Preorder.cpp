class Solution {
public:
    TreeNode* build(TreeNode* root,int x)
    {
     if(root==NULL)
         root=new TreeNode(x);
     else if(x<root->val)
         root->left=build(root->left,x);
     else
         root->right=build(root->right,x);
     return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
     TreeNode* root=NULL;
     int n=preorder.size();
     for(int i=0;i<n;i++)
         root=build(root,preorder[i]);
     return root;
    }
};
