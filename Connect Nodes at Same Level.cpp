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

void connect(Node *p)
{
  queue<Node*>q;
  q.push(p);
  q.push(NULL);
  while(!q.empty())
  {
  Node *cur=q.front();
  q.pop();
  if(cur!=NULL)
  {
    cur->nextRight=q.front();
    if(cur->left)
     q.push(cur->left);
    if(cur->right)
     q.push(cur->right);

  }
  else if(!q.empty())
    q.push(NULL);
  }
}
