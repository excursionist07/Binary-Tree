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


void CreateNode(int parent[],int i,Node *created[],Node **root)
{
 if(created[i])
   return;
 created[i]=new Node(i);
 if(parent[i]==-1)
 {
  *root=created[i];
  return;
 }
 if(created[parent[i]]==NULL)
    CreateNode(parent,parent[i],created,root);
 //created[i]=GetNewNode(i);
 Node *zz=created[parent[i]];
 if(zz->left==NULL)
  zz->left=created[i];
 else
  zz->right=created[i];

}

Node *createTree(int parent[], int n)
{
  Node *created[n];
  for(int i=0;i<n;i++)
    created[i]=NULL;
  Node *root=NULL;
  for(int i=0;i<n;i++)
  {
   CreateNode(parent,i,created,&root);
  }
  return root;
}
