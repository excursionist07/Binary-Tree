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

int minDepth(Node *node)
{
   if(node==NULL)
    return 0;
   if(node->left==NULL && node->right==NULL)
    return 1;
   if(node->left==NULL)
    return 1+minDepth(node->right);
   if(node->right==NULL)
    return 1+minDepth(node->left);
  return 1+min(minDepth(node->left),minDepth(node->right));
}
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
