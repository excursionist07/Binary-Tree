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

// O(n) space
/*void doit(Node *root,vector<Node*>&vec)
{
 if(!root)
  return;
 if(!root->left && !root->right)
  vec.push_back(root);
 if(root->left)
  doit(root->left,vec);
 if(root->right)
  doit(root->right,vec);
}*/

// o(1) space
void doit1(Node* root,Node*  &temp)
{
 if(!root)
  return;
 if(!root->left && !root->right)
 {
  if(temp)
  {
    swap(temp->data,root->data);
    temp=NULL;
  }
  else
   temp=root;
 }
 doit1(root->left,temp);
 doit1(root->right,temp);

}
void pairwiseSwap(Node *root)
{
  /*vector<Node*>vec;
  doit(root,vec);
  int size=(vec.size()%2==0) ? vec.size():vec.size()-1;
  for(int i=0;i<size;i+=2)
   swap(vec[i]->data,vec[i+1]->data);*/
   Node *temp=NULL;
   doit1(root,temp);
}
