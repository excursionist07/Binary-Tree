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

vector<int>vec;
int x;
void in1(Node *root)
{
 if(root==NULL)
  return;
 in1(root->left);
 vec.push_back(root->data);
 in1(root->right);
}

Node *in2(Node *root)
{
 if(root==NULL)
  return NULL;
 in2(root->left);
 root->data=vec[x];
 x++;
 in2(root->right);
 return root;
}

Node *binaryTreeToBST(Node *root)
{
 vec.clear();
 x=0;
 if(root==NULL)
  return NULL;
 in1(root);
 sort(vec.begin(),vec.end());
 Node *temp=in2(root);
 return temp;

}
