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

void pre(Node *root,vector<int> &A)
{
 if(root==NULL)
 {
  A.push_back(-1);
  return;
 }
 A.push_back(root->data);
 pre(root->left,A);
 pre(root->right,A);
}
int in;

void serialize(Node *root,vector<int> &A)
{
  A.clear();
   in=0;
  pre(root,A);

}

Node* GetNewNode(int x)
{
 Node* temp=new Node();
  temp->data=x;
 temp->left=temp->right=NULL;
 return temp;
}

Node * deSerialize(vector<int> &A)
{
  if(in==A.size() || A[in]==-1)
  {
    in++;
    return NULL;
  }
  Node *temp=GetNewNode(A[in]);
  in++;
  temp->left=deSerialize(A);
  temp->right=deSerialize(A);


  return temp;
}
