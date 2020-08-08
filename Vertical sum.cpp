
/*void doit(Node *root,int hd,map<int,int>&mp)//RECURSIVE
{
 if(!root)
  return;
 doit(root->left,hd-1,mp);
 doit(root->right,hd+1,mp);
 mp[hd]+=root->data;

}*/
vector <int> verticalSum(Node *root) 
{
  vector<int>vv;
  if(!root)
   return vv;
  map<int,int>mp;
  //doit(root,0,mp);
  queue<pair<Node*,int>>q;// ITERATIVE
  int hd=0;
  q.push(make_pair(root,hd));
  while(!q.empty())
  {
    pair<Node*,int>temp=q.front();
    q.pop();
    Node* cur=temp.first;
    hd=temp.second;
   mp[hd]+=cur->data;
    if(cur->left)
      q.push(make_pair(cur->left,hd-1));
    if(cur->right)
       q.push(make_pair(cur->right,hd+1));
  }
  
  for(auto xx:mp)
   vv.push_back(xx.second);
  return vv;
  
  
 
}
/*
Given a Binary Tree, find the vertical sum of the nodes that are in the same vertical line. Print all sums through different vertical lines.
We need to check the Horizontal Distances from the root for all nodes. If two nodes have the same Horizontal Distance (HD), then they are on the same vertical line. 
*/
