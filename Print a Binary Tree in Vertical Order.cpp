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

void verticalOrder(Node *root)
{
   if(root==NULL)
     return;
   int hd=0;
   queue<pair<Node*,int>>q;
   q.push(make_pair(root,hd));
   map<int,vector<int>>mp;
   while(!q.empty())
   {
     pair<Node*,int>temp=q.front();
     q.pop();
     hd=temp.second;
     Node *poke=temp.first;
     mp[hd].push_back(poke->data);
     if(poke->left!=NULL)
       q.push(make_pair(poke->left,hd-1));
     if(poke->right!=NULL)
       q.push(make_pair(poke->right,hd+1));
    }
    map<int,vector<int>>::iterator itr;
    for(itr=mp.begin();itr!=mp.end();++itr)
    {
      for(int i=0;i<itr->second.size();i++)
      {
         cout<<itr->second[i]<<" ";
      }

    }
   // cout<<"\n";

}
