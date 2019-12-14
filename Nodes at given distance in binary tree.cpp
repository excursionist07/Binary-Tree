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

void makeparent(node *parent,node *root,map<node*,node*>&mp)
{
 mp[root]=parent;
 if(root->left)
   makeparent(root,root->left,mp);
 if(root->right)
   makeparent(root,root->right,mp);
}

int printkdistanceNode(node* root, node* target , int k)
{
 map<node*,node*>mp;
 bool vis[501]={0};
 makeparent(NULL,root,mp);
 queue<node*>q;
 q.push(target);
 int cnt=0;
 while(!q.empty())
 {
  int size=q.size();
  while(size>0)
  {
    if(cnt==k)
   {
    node *temp=q.front();
    q.pop();
    cout<<temp->data<<" ";
   }
    else
    {
    node *temp=q.front();
    q.pop();
    vis[temp->data]=1;
    if(temp->left && !vis[temp->left->data])
      q.push(temp->left);
    if(temp->right && !vis[temp->right->data])
      q.push(temp->right);
    if(mp[temp]!=NULL && !vis[mp[temp]->data])
      q.push(mp[temp]);
    }
    size--;
  }
  cnt++;
 }
}
