// Vertical Traversal of Binary Tree-->based on horizontal distance -i.e(left--> -1 & right-->1)

vector<int> verticalOrder(Node *root)
{
   vector<int>ans;
     if(!root)
         return ans;
     map<int,vector<int>>mp;
     queue<pair<Node*,int>>q;
     int hd=0;
     q.push(make_pair(root,hd));
     while(!q.empty())
     {
      pair<Node*,int>temp=q.front();
      q.pop();
      Node* cur=temp.first;
      hd=temp.second;
      mp[hd].push_back(cur->data);
      if(cur->left)
          q.push(make_pair(cur->left,hd-1));
      if(cur->right)
          q.push(make_pair(cur->right,hd+1));

     }
     for(auto xx:mp)
     {

      for(auto yy:xx.second)
      {
       ans.push_back(yy);
      }

     }

     return ans;
}

// Vertical sum

/*void doit(Node *root,int hd,map<int,int>&mp)//RECURSIVE
{
 if(!root)
  return;
 mp[hd]+=root->data;
 doit(root->left,hd-1,mp);
 doit(root->right,hd+1,mp);
 
}*/
vector <int> verticalSum(Node *root) 
{
  vector<int>vv;
  if(!root)
   return vv;
  map<int,int>mp;
  //doit(root,0,mp); // RECURSIVE
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

// Vertical Width of a Binary Tree

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




