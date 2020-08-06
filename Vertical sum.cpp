
Node * printVerticalUtil(Node *root,int hd,map<int,int>&mp)
{
 if(root==NULL)
  return NULL;
 printVerticalUtil(root->left,hd-1,mp);
 printVerticalUtil(root->right,hd+1,mp);
 mp[hd]+=root->data;

}
vector <int> verticalSum(Node *root) 
{
  vector<int>vv;
  map<int,int>mp;
  printVerticalUtil(root,0,mp);
  map<int,int>::iterator itr;
  for(itr=mp.begin();itr!=mp.end();++itr)
    vv.push_back(itr->second);
  return vv;
 
}
/*
Given a Binary Tree, find the vertical sum of the nodes that are in the same vertical line. Print all sums through different vertical lines.
We need to check the Horizontal Distances from the root for all nodes. If two nodes have the same Horizontal Distance (HD), then they are on the same vertical line. 
*/
