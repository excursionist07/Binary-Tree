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

vector<int>v1,v2;
void in1(Node *r1)
{
  if(r1==NULL)
    return;
  in1(r1->left);
  v1.push_back(r1->data);
  in1(r1->right);

}
void in2(Node *r2)
{
  if(r2==NULL)
    return;
  in2(r2->left);
  v2.push_back(r2->data);
  in2(r2->right);

}
bool isIdentical(Node *r1, Node *r2)
{
  v1.clear();
  v2.clear();
  if(r1==NULL && r2==NULL)
    return 1;
  in1(r1);
  in2(r2);
  int ff=0;
  if(v1.size()!=v2.size())
    return 0;
  else
  {
    for(int i=0;i<v1.size();i++)
    {
      if(v1[i]==v2[i])
        continue;
      else
      {
         ff=1;
         break;
      }
    }
    if(ff==0)
      return 1;
    else
      return 0;
  }
}
