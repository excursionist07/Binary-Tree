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
