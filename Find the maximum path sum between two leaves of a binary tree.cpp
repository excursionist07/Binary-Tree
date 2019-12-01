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

int maxPathUtil(Node *root,int &res)
{
 if(root==NULL)
  return 0;
 if(root->left==NULL && root->right==NULL)
  return root->data;
 int ls=maxPathUtil(root->left,res);
 int rs=maxPathUtil(root->right,res);
 if(root->left && root->right)
 {
  res=max(res,ls+rs+root->data);
  return max(ls,rs)+root->data;
 }
 return (root->left==NULL) ? rs+root->data : ls+root->data;
}
int maxPathSum(struct Node *root)
{
 int res=INT_MIN;
 maxPathUtil(root,res);
 return res;
}
