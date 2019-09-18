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

void printSpiral(Node *root)
{

  stack<Node*>s1;
  stack<Node*>s2;
  s1.push(root);
  while(!s1.empty() || !s2.empty())
  {
    while(!s1.empty())
    {
     Node *temp=s1.top();
     s1.pop();
     cout<<temp->data<<" ";
     if(temp->right)
       s2.push(temp->right);
     if(temp->left)
       s2.push(temp->left);
    }
    while(!s2.empty())
    {
     Node *temp=s2.top();
     s2.pop();
     cout<<temp->data<<" ";
     if(temp->left)
       s1.push(temp->left);
     if(temp->right)
       s1.push(temp->right);
    }
  }
}
