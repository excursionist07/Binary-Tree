// Same Tree or Identical Tree

class Solution {
public:
    bool doit(TreeNode* p,TreeNode* q)
    {
     if(!p && !q)
         return true;
     if(p && q && p->val==q->val)
         return doit(p->left,q->left) && doit(p->right,q->right);
     return false;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
     if(!p && !q)
         return true;
     return doit(p,q);
    }
};

// Symmetric Tree

class Solution {
public:
    bool doit(TreeNode* p,TreeNode* q)
    {
     if(!p && !q)
         return true;
     if(p && q && p->val==q->val)
         return doit(p->left,q->right) && doit(p->right,q->left);
     return false;
    }
    bool isSymmetric(TreeNode* root) 
    {
     if(!root)
         return true;
     return doit(root,root);
    }
};

// Invert Tree

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
      if(!root)
          return NULL;
      if(root->left)
          invertTree(root->left);
      if(root->right)
          invertTree(root->right);
      TreeNode* temp=root->left;
      root->left=root->right;
      root->right=temp;
      return root;
    }
};

// Isomorphic Tree

bool IsSymmetric(Node *root1,Node *root2)
{
 if(!root1 && !root2)
  return true;
 if(root1 && root2 && root1->data==root2->data)
  return IsSymmetric(root1->left,root2->right) &&  IsSymmetric(root1->right,root2->left);
 return false;
}

bool IsIdentical(Node *root1,Node *root2)
{
 if(!root1 && !root2)
  return true;
 if(root1 && root2 && root1->data==root2->data)
  return IsIdentical(root1->left,root2->left) &&  IsIdentical(root1->right,root2->right);
 return false;
}

bool isIsomorphic(Node *root1,Node *root2) // Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped.
{
 return IsSymmetric(root1,root2) || IsIdentical(root1,root2);
}

// Check if two trees are mirror or not

Node* makemirror(Node* root)
{
 if(!root)
  return NULL;
 if(root->left)
  makemirror(root->left);
 if(root->right)
  makemirror(root->right);
 Node* temp=root->left;
 root->left=root->right;
 root->right=temp;
 return root;
}
bool IsIdentical(Node* a,Node* b)
{
 if(!a && !b)
  return true;
 if(a && b && a->data==b->data)
  return IsIdentical(a->left,b->left) && IsIdentical(a->right,b->right);
 return false;
}
int areMirror(Node* a, Node* b) 
{
  if(!a && !b)
   return 1;
  makemirror(a);
 return IsIdentical(a,b);
}
