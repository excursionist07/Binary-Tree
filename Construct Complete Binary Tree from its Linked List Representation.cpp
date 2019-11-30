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

TreeNode* Create(int x)
{
 TreeNode* temp=new TreeNode(x);
  //temp->data=x;
 temp->left=temp->right=NULL;
 return temp;
}
void convert(Node *head, TreeNode *&root)
{
 queue<TreeNode*>q;
 if(head==NULL)
 {
    root=NULL;
    return;
 }
 root=Create(head->data);
 q.push(root);
 head=head->next;
 while(head)
 {
  TreeNode* u=q.front();
  q.pop();
  u->left=Create(head->data);
  q.push(u->left);
  head=head->next;

  if(head)
  {
    u->right=Create(head->data);
    q.push(u->right);
    head=head->next;
  }
 }
 //return root;

}
