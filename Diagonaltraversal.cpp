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

void dt(Node* root,int d,map<int,vector<int>>&mp)
{
 if(!root)
   return;
 mp[d].push_back(root->data); // Store all nodes of same line together as a vector 
 dt(root->left, d + 1,mp);  // Increase the vertical distance if left child 
 dt(root->right, d,mp); // Vertical distance remains same for right child
}

void diagonalPrint(Node *root)
{
  if(root==NULL)
   return;
  map<int,vector<int>>mp;
  dt(root,0,mp);
  for(auto xx:mp)
  {
   for(auto yy:xx)
   {
     cout<<yy<<" ";
   }
   cout<<"\n";
  }
     
}
