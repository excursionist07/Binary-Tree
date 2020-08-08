void doit(Node* root,int dd,map<int,int>&mp)
{
 if(!root)
  return;
 doit(root->left,dd-1,mp);
 doit(root->right,dd+1,mp);
 mp[dd]+=root->data;
}
int verticalWidth(Node* root)
{
  if(!root)
   return 0;
  map<int,int>mp;
  doit(root,0,mp);
  return mp.size();
}
