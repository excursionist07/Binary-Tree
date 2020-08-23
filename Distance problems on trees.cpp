// Min distance between two given nodes of a Binary Tree

Node* lca(Node* root,int a,int b)
{
 if(root==NULL)
  return NULL;
 if(root->data==a || root->data==b)
   return root;
 Node* l=lca(root->left,a,b);
 Node* r=lca(root->right,a,b);
 if(l && r)return root;
 if(!l && !r)return NULL;
 if(l) return l;
 if(r) return r;

}
int dist(Node* root,int a) // it is necessary to find LCA b'coz whave to only go down
{
 if(root==NULL)
  return 0;
 if(root->data==a)
   return 0;
 return 1+min(dist(root->left,a),dist(root->right,a));
}
int findDist(Node* root, int a, int b)
{
   Node* LCA=lca(root,a,b);
   return dist(LCA,a)+dist(LCA,b); // OR(dist(a,root)+dist(b,root)-2*dist(LCA,root))
}

// Minimum Depth of a Binary Tree

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

int minDepth(Node *node)
{
   if(node==NULL)
    return 0;
   if(node->left==NULL && node->right==NULL)
    return 1;
   if(node->left==NULL)
    return 1+minDepth(node->right);
   if(node->right==NULL)
    return 1+minDepth(node->left);
  return 1+min(minDepth(node->left),minDepth(node->right)); // if depth is just edges remove 1+
}
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.



// Shortest distance in infinite tree

#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
 */


int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll x,y;
  cin>>x>>y;
  ll cnt=0;
  while(x!=y && x>0 && y>0)
  {
   if(x>y)
    x/=2;
   else
    y/=2;
   cnt++;
  }
  cout<<cnt<<"\n";
 }
 return 0;
}


// K distance nodes from all leaf node

void doit(Node* root,int k,unordered_set<Node*>&ss,vector<Node*>vv)
{
 if(!root)
  return;
 vv.push_back(root);
 if(!root->left && !root->right && vv.size()>k)
  ss.insert(vv[vv.size()-k-1]);
 doit(root->left,k,ss,vv);
 doit(root->right,k,ss,vv);
}
int printKDistantfromLeaf(Node* root, int k)
{
 unordered_set<Node*>ss;
 vector<Node*>vv;
 if(!root)
  return 0;
 doit(root,k,ss,vv);
 return ss.size();
}

// K distance nodes

// function should print the nodes at k distance from root
void printKdistance(Node *root, int k)
{
  if(root==NULL)
   return;
  if(k==0)
   cout<<root->data<<" ";
  else
  {
    printKdistance(root->left,k-1);
    printKdistance(root->right,k-1);
  }
}


// from any target Node


class Solution {
public:
   
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
     vector<int>vv;
     if(!root || !target)
         return vv;
     unordered_map<TreeNode*,TreeNode*>parent;
     unordered_map<TreeNode*,bool>vis;
     queue<TreeNode*>q;
     q.push(root);
     while(!q.empty())
     {
      TreeNode* cur=q.front();
      q.pop();
      if(cur->left)
      {
       parent[cur->left]=cur;
       q.push(cur->left);
      }
      if(cur->right)
      {
       parent[cur->right]=cur;
       q.push(cur->right);
      }
     }
     int cnt=0;
     q.push(target);
     vis[target]=1;
     while(!q.empty())
     {
      int zz=q.size();
      if(cnt++==K)
          break;
      for(int i=0;i<zz;i++)
      {
       TreeNode* cur=q.front();
       q.pop();
       if(cur->left && !vis[cur->left])
       {
        q.push(cur->left);
        vis[cur->left]=1;
       }
       if(cur->right && !vis[cur->right])
       {
        q.push(cur->right);
        vis[cur->right]=1;
       }
       if(parent[cur] && !vis[parent[cur]])
       {
        q.push(parent[cur]);
        vis[parent[cur]]=1;
       }
       
      }
     }
     while(!q.empty())
     {
      TreeNode* cur=q.front();
      q.pop();
      vv.push_back(cur->val);
     }
     return vv;
     
     
    }
};
