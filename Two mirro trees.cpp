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

Node* miroor1(Node *root)
{
  if(root==NULL)
    return NULL;
  Node *temp;
  miroor1(root->left);
  miroor1(root->right);

  temp=root->left;
  root->left=root->right;
  root->right=temp;

  return root;
}
vector<int>v1,v2;

void in1(Node *root)
{
 if(root==NULL)
  return;
 in1(root->left);
 v1.push_back(root->data);
 in1(root->right);

}

void in2(Node *root)
{
 if(root==NULL)
  return;
 in2(root->left);
 v2.push_back(root->data);
 in2(root->right);

}
int areMirror(Node* a, Node* b)
{
  v1.clear();
  v2.clear();
  Node* temp=miroor1(a);
  in1(temp);
  in2(b);
  if(v1.size()==v2.size())
  {
    for(int i=0;i<v1.size();i++)
    {
     if(v1[i]!=v2[i])
       return 0;
    }
    return 1;
  }
  else
   return 0;
}
