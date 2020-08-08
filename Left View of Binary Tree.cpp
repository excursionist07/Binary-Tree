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

void printleftview(Node *root,int level,int *maxlevel)// first element of each level
{
    if(root==NULL)
     return;
    if(level>*maxlevel) // when level becomes greater than maxlevel then it is the first node of that level & that node is in left view.
    {
     cout<<root->data<<" ";
     *maxlevel=level;
    }
    // just flip below two statements then it becomes right view of BT
    printleftview(root->left,level+1,maxlevel);
    printleftview(root->right,level+1,maxlevel);
}
void leftView(Node *root)
{
  int maxlevel=0;
  printleftview(root,1,&maxlevel);

}
