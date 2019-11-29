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


Node *ConstructTreeUtil(int pre[],int preLN[],int *index,int n)
{
 int zz=*index;
 if(*index==n-1)
  return NULL;
 Node *temp=new Node(pre[zz]);
 temp->left=NULL;
 temp->right=NULL;
 (*index)++;
 if(preLN[zz]=='N')
 {
  temp->left=ConstructTreeUtil(pre,preLN,index,n);
  temp->right=ConstructTreeUtil(pre,preLN,index,n);
 }
 return temp;

}
Node *ConstructTree(int pre[],int preLN[],int n)
{
 int index=0;
 return ConstructTreeUtil(pre,preLN,&index,n);
}
