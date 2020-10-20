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

// Symmetric Tree ---> a tree which is mirror image of itself 

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

bool doit(Node* a,Node* b)
{
 if(!a && !b)
  return true;
 if(a && b && a->data==b->data)
  return doit(a->left,b->right) && doit(a->right,b->left);
 return false;
}
int areMirror(Node* a, Node* b) 
{
  if(!a && !b)
   return true;
  return doit(a,b);
}


// 110. Check for Balanced Tree--->  A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

class Solution {
public:
    int height(TreeNode* root)
    {
     if(!root)
         return -1;
     else
     {
      int LH=height(root->left);
      int RH=height(root->right);
      return 1+max(LH,RH);
     }
    }
    bool isBalanced(TreeNode* root)
    {
      if(!root)
          return 1;
      int L=height(root->left);
      int R=height(root->right);
      
      if(abs(L-R)<=1 && isBalanced(root->left) && isBalanced(root->right))
          return 1;
     return 0;
    }
};

// 958. Check Completeness of a Binary Tree
/* -->In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.*/

/*
Use BFS to do a level order traversal,
add childrens to the bfs queue,
until we met the first empty node.

For a complete binary tree,
there should not be any node after we met an empty one.
*/

class Solution {
public:
   
    bool isCompleteTree(TreeNode* root) 
    {
     if(!root)
      return true;
     queue<TreeNode*>q;
     q.push(root);
     bool ff=true;
     while(!q.empty())
     {
      TreeNode* cur=q.front();
      q.pop();
      if(cur==NULL)
          ff=false;
      else
      {
       if(ff==false)
           return false;
       q.push(cur->left);
       q.push(cur->right);
      }
         
     }
     return true;
    }
};


// 563.Tilt of Binary Tree

/*
The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
The tilt of the whole tree is defined as the sum of all nodes' tilt.----VERY IMPORTANT,it should not be misunderstood just to find abs(LS-RS) ONLY.
*/

class Solution {
public:
    int sum(TreeNode* root)
    {
     if(!root)
         return 0;
     return sum(root->left)+root->val+sum(root->right);
    }
    int findTilt(TreeNode* root) 
    {
     if(!root)
         return 0;
     int Lsum=sum(root->left);
     int Rsum=sum(root->right);
     
     return abs(Lsum-Rsum)+findTilt(root->left)+findTilt(root->right);
     
    }
};

//  Expression Tree

int evalTree(node* root) 
{
  if(!root)
   return 0;
  if(!root->left && !root->right)
   return stoi(root->data);
  int l=evalTree(root->left);
  int r=evalTree(root->right);
  if(root->data=="+")
   return l+r;
  if(root->data=="-")
   return l-r;
  if(root->data=="*")
   return l*r;
  if(root->data=="/")
   return l/r;
  
}
