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
 Node *temp=new Node(x);

 temp->left=NULL;
 temp->right=NULL;
 temp->random=NULL;
 return temp;

}
Node* cloneTree(Node* tree)
{
 if(tree==NULL)
  return NULL;
 Node *temp=create(tree->data);
 temp->random=tree->random;
 temp->left=cloneTree(tree->left);
 temp->right=cloneTree(tree->right);
 temp->random=tree->random;

 return temp;


}
