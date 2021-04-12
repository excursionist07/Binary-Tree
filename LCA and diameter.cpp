// LCA in BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
     if(!root)
         return NULL;
     if(root->val>p->val && root->val>q->val)
        return lowestCommonAncestor(root->left,p,q);
     if(root->val<p->val && root->val<q->val)
         return lowestCommonAncestor(root->right,p,q);
     return root;
    }
};


// LCA in a Binary Tree

Method 1 (By Storing root to n1 and root to n2 paths):
Following is simple O(n) algorithm to find LCA of n1 and n2.
1) Find path from root to n1 and store it in a vector or array.
2) Find path from root to n2 and store it in another vector or array.
3) Traverse both paths till the values in arrays are same. Return the common element just before the mismatch.

  
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) //o(n) && O(1)
    {
     if(!root)
         return NULL;
    if(root->val==p->val || root->val==q->val)
        return root;
    TreeNode* l=lowestCommonAncestor(root->left,p,q);
    TreeNode* r=lowestCommonAncestor(root->right,p,q);
    if(l && r) return root;
    if(l) return l;
    if(r) return r;
    return NULL;
    }
};

// Kth Ancestor in a Tree

void makeparent(Node* root,int parent[])
{
 parent[root->data]=-1;
 queue<Node*>q;
 q.push(root);
 while(!q.empty())
 {
  Node* cur=q.front();
  q.pop();
  if(cur->left)
  {
    parent[cur->left->data]=cur->data;
    q.push(cur->left);
  }
  if(cur->right)
  {
    parent[cur->right->data]=cur->data;
    q.push(cur->right);
  }
 }
}
int kthAncestor(Node *root, int k, int node)
{
  if(!root)
   return -1;
  if(k==0)
   return node;
  int parent[10007];
  makeparent(root,parent);
  int cnt=0;
  while(node!=-1)
  {
    node=parent[node];
    cnt++;
    if(cnt==k)
     return node;
  }
  return -1;
}

// Inorder Successor in BST

//In BST, Inorder successor of a node is the next node in Inorder traversal of the Binary Tree. Inorder Successor is NULL for the last node in Inorder traversal.
 
Node *minValue(Node *root)
{
 if(root==NULL)
  return NULL;
 else if(root->left==NULL)
   return root;
 else
   minValue(root->left);
}
Node * inOrderSuccessor(Node *root, Node *x)// O(h) && O(1)
{
  if(x->right!=NULL)
    return minValue(x->right);
 Node *succ=NULL;
 while(root!=NULL)
 {
  if(root->data>x->data)
  {
    succ=root;
    root=root->left;
  }
  else if(root->data<x->data)
    root=root->right;
  else
    break;
 }
 return succ;
}

// Inorder Predecessor in BST

//In Binary Tree, Inorder predecessor of a node is the previous node in Inorder traversal of the Binary Tree. 


Node *MaxValue(Node *root)
{
 if(root==NULL)
  return NULL;
 else if(root->right==NULL)
   return root;
 else
   MaxValue(root->right);
}

Node * inOrderPredecessor(Node *root, Node *x)
{
 if(x->left!=NULL)
    return MaxValue(x->left);
 Node *pred=NULL;
 while(root!=NULL)
 {
  if(root->data>x->data)
    root=root->left;
  else if(root->data<x->data)
  {
   pred=root;
   root=root->right;
  }
  else
    break;
 }
 return pred;
}

// pred and succ of a given key (gfg)

void FindPre(Node* root,Node*& pre,int key)
{
 if(!root)
  return;
 while(root)
 {
  if(root->key>=key)
   root=root->left;
  else if(root->key<key)
  {
    pre=root;
    root=root->right;
  }
 }
}
void FindSuc(Node* root,Node*& suc,int key)
{
  if(!root)
   return;
  while(root)
  {
    if(root->key>key)
    {
     suc=root;
     root=root->left;
    }
    else if(root->key<=key)
     root=root->right;
  }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
 pre=NULL,suc=NULL;
 if(!root)
  return;
 FindPre(root,pre,key);
 FindSuc(root,suc,key);


}

// Diameter of tree

int height(Node *root)
{
  if(root==NULL)
    return 0;
 int LH=height(root->left);
 int RH=height(root->right);
 return max(LH,RH)+1;
}
int diameter(Node* node)
{
  if(node==NULL)
    return 0;
 int left_ht=height(node->left);
 int right_ht=height(node->right);

 int left_dm=diameter(node->left);
 int right_dm=diameter(node->right);
 return max(1+left_ht+right_ht,max(left_dm,right_dm));//if count from node and if asked about from edge count just remove "1+" from this line

}
