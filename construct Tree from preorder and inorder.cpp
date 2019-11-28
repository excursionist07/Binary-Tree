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

int search(int in[],int start,int end,int p)
{
 for(int i=start;i<=end;i++)
 {
    if(in[i]==p)
     return i;
 }
}
Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
  
  if(inStrt>inEnd)
   return NULL;
  Node* temp=new Node(pre[preIndex]);
  //temp->data=;
  temp->left=NULL;
  temp->right=NULL;
  preIndex++;
  
  if(inStrt==inEnd)
   return temp;
  int zz=search(in,inStrt,inEnd,temp->data);
  temp->left=buildTree(in,pre,inStrt,zz-1);
  temp->right=buildTree(in,pre,zz+1,inEnd);
  
  return temp;
   
}
