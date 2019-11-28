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

int ind;
int search(int in[],int start,int end,int p)
{
    int i;
 for(i=start;i<=end;i++)
 {
   if(in[i]==p)
     break;
 }
 return i;
}
Node *part(int in[],int post[],int start,int end)
{
 if(start>end)
  return NULL;
 Node *temp=new Node();
 temp->data=post[ind--];
 temp->left=NULL;
 temp->right=NULL;

 if(start==end)
  return temp;
 int zz=search(in,start,end,temp->data);
 temp->left=part(in,post,start,zz-1);
 temp->right=part(in,post,zz+1,end);

 return temp;

}
Node *buildTree(int in[], int post[], int n)
{
 ind=n-1;
 return part(in,post,0,n-1);

}

