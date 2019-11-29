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

Node *diagonalSumUtil(Node *root,int dd,map<int,int>&mp)
{
 if(root==NULL)
    return;
 mp[dd]+=root->data;
 diagonalSumUtil(root->left,dd+1,mp);
 diagonalSumUtil(root->right,dd,mp);
}

void diagonalSum(Node *root)
{
 map<int,int>mp;
 diagonalSumUtil(root,0,mp);

 map<int,int>::iterator itr;
 for(itr=mp.begin();itr!=mp.end();++itr)
    cout<<itr->second<<" ";

}
