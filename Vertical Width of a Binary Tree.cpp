Node *verticalWidthUtil(Node *root,int hd,map<int,int>&mp)
{
 if(root==NULL)
  return NULL;
 verticalWidthUtil(root->left,hd-1,mp);
 mp[hd]+=root->data;
 verticalWidthUtil(root->right,hd+1,mp);
}
int verticalWidth(Node* root)
{
  if(root==NULL)
   return 0;
  map<int,int>mp;
  verticalWidthUtil(root,0,mp);
  return mp.size();
}
