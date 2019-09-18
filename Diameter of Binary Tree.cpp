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

int height(Node *root)
{
  if(root==NULL)
    return 0;
 int LH=height(root->left);
 int RH=height(root->right);
 return max(LH,RH)+1;
}
int diameter(Node* node)
{
  if(node==NULL)
    return 0;
 int left_ht=height(node->left);
 int right_ht=height(node->right);

 int left_dm=diameter(node->left);
 int right_dm=diameter(node->right);
 return max(1+left_ht+right_ht,max(left_dm,right_dm));

}
