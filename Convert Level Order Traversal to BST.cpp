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


Node* create(int x)
{
 Node* temp=new Node(x);
 //temp->data=x;
 temp->left=NULL;
 temp->right=NULL;
 return temp;
}
Node* levelorder(Node* root,int x)
{
 if(root==NULL)
 {
  root=create(x);
  return root;
 }
 if(x<=root->data)
  root->left=levelorder(root->left,x);
 else
  root->right=levelorder(root->right,x);
 return root;
}
Node* constructBst(int arr[], int n)
{
    if(n==0)
     return NULL;
   Node* root=NULL;
   for(int i=0;i<n;i++)
    root=levelorder(root,arr[i]);

   return root;


}
