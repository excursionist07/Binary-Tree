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

// 449. Serialize and Deserialize BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    
    void preorder(TreeNode* root,string& str)
    {
     if(!root)
       return;
     str+=to_string(root->val) + ",";
     preorder(root->left,str);
     preorder(root->right,str);
    }
    
    string serialize(TreeNode* root)
    {
     if(!root)return " ";
     string str="";
     preorder(root,str);
     return str;
    
    }

    // Decodes your encoded data to tree.
    int go(string& data,int& pos)
    {
     pos=data.find(',');
     int value=stoi(data.substr(0,pos));
     return value;
    }
    TreeNode* doit(string& data,int mn,int mx)
    {
     if(!data.length())return NULL;
     int pos=0;
     int value=go(data,pos);
     if(value<mn || value>mx)return NULL;
     data=data.substr(pos+1);// after using number delete the used & this statement should be below upper statement b'coz in recursion it is needed
     
     TreeNode* cur=new TreeNode(value);
     cur->left=doit(data,mn,cur->val);
     cur->right=doit(data,cur->val,mx);
     return cur;
    }
    
    TreeNode* deserialize(string data)
    {
      if(data==" ")return NULL;
      return doit(data,INT_MIN,INT_MAX);
      
    }
};

// 297. Serialize and Deserialize Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode* root,string& str)
    {
     if(!root)
     {
      str+="#";
      str+=",";
      return;
     }
     str+=to_string(root->val)+",";
     preorder(root->left,str);
     preorder(root->right,str);
    }
    string serialize(TreeNode* root) 
    {
     if(!root)return "#";
     string str="";
     preorder(root,str);
     return str; // (str =1,2,#,#,3,4,#,#,5,#,#,) foor Example 1.
    }

    // Decodes your encoded data to tree.
    int go(string& data,int& pos)
    {
     pos=data.find(',');
     int value=stoi(data.substr(0,pos));
     return value;
    }
    
    TreeNode* doit(string& data)
    {
     if(data[0]=='#') // it means NULL
     {
       if(data.length()>1)
           data=data.substr(2); // eleminating '#' and ',' from data
       return NULL;
     }
     int pos=0;
     int value=go(data,pos);
     data=data.substr(pos+1);
     TreeNode* cur=new TreeNode(value);
     cur->left=doit(data);
     cur->right=doit(data);
     return cur;
    }
    TreeNode* deserialize(string data) 
    {
     return doit(data);
    }
};



