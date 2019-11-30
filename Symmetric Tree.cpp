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

bool symmetric(struct Node* root1,struct Node* root2)
{
 if(root1==NULL && root2==NULL)
  return true;
 if(root1 && root2 && root1->key==root2->key)
  return symmetric(root1->left,root2->right) && symmetric(root1->right,root2->left);

  return false;
}
bool isSymmetric(struct Node* root)
{
 return symmetric(root,root);
}
