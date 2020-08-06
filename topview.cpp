#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

void topView(struct Node *root)
{
  if(root==NULL)
   return;
  int hd=0;
  map<int,int>mp;
  queue<pair<Node*,int>>q;
  q.push(make_pair(root,hd));
  while(!q.empty())
  {
    pair<Node*,int>temp=q.front();
    q.pop();
    Node *cur=temp.first;
    hd=temp.second;
    if(mp.count(hd)==0)
      mp[hd]=cur->data;
    if(cur->left!=NULL)
      q.push(make_pair(cur->left,hd-1));
    if(cur->right!=NULL)
      q.push(make_pair(cur->right,hd+1));
  }
  map<int,int>::iterator itr;
  for(itr=mp.begin();itr!=mp.end();++itr)
    cout<<itr->second<<" ";
}

/*
A node x is there in output if x is the topmost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, 
and that of right child is horizontal distance of x plus 1.
*/
