void doit(Node* root,int k,unordered_set<Node*>&ss,vector<Node*>vv)
{
 if(!root)
  return;
 vv.push_back(root);
 if(!root->left && !root->right && vv.size()>k)
  ss.insert(vv[vv.size()-k-1]);
 doit(root->left,k,ss,vv);
 doit(root->right,k,ss,vv);
}
int printKDistantfromLeaf(Node* root, int k)
{
 unordered_set<Node*>ss;
 vector<Node*>vv;
 if(!root)
  return 0;
 doit(root,k,ss,vv);
 return ss.size();
}
