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



void preorder(Node* root)
{
  stack<Node*>stk;
  stk.push(root);
  while(!stk.empty())
  {
    Node *cur=stk.top();
    stk.pop();
    cout<<cur->data<<" ";
    if(cur->right)
      stk.push(cur->right);
    if(cur->left)
      stk.push(cur->left);
  }
}


void inOrder(Node* root)
{
  if(root==NULL)
   return;

  stack<Node*>stk;
  Node *cur=root;
  while(!stk.empty() || cur)
  {

    while(cur)
    {
     stk.push(cur);
     cur=cur->left;
    }
    cur=stk.top();
    stk.pop();
    cout<<cur->data<<" ";
    cur=cur->right;
  }

}

void postOrder(Node* root) // USING TWO STACKS 
{
 if(root==NULL)
  return;
 stack<Node*>s1,s2;
 s1.push(root);
 while(!s1.empty())
 {
  Node *cur=s1.top();
  s1.pop();
  s2.push(cur);
  if(cur->left)
   s1.push(cur->left);
  if(cur->right)
   s1.push(cur->right);

 }
 while(!s2.empty())
 {
  Node *temp=s2.top();
  s2.pop();
  cout<<temp->data<<" ";
 }
}

//USING ONE STACK

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* last = NULL;
        while (root || !todo.empty()) {
            if (root) {
                todo.push(root);
                root = root -> left;
            } else {
                TreeNode* node = todo.top();
                if (node -> right && last != node -> right) { // to check if right subtree is visited or not
                    root = node -> right;
                } else {
                    nodes.push_back(node -> val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return nodes;
    }
};

