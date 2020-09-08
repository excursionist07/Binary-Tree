// Top View

void topView(struct Node *root)
{
  if(!root)
   return;
  map<int,int>mp;
  queue<pair<Node*,int>>q;
  int hd=0;
  q.push(make_pair(root,hd));
  while(!q.empty())
  {
    pair<Node*,int>temp=q.front();
    q.pop();
    Node* cur=temp.first;
    hd=temp.second;
    if(mp.count(hd)==0)
      mp[hd]=cur->data;
    if(cur->left)
      q.push(make_pair(cur->left,hd-1));
    if(cur->right)
       q.push(make_pair(cur->right,hd+1));
     
  }
  for(auto xx:mp)
   cout<<xx.second<<" ";
}




/*
A node x is there in output if x is the topmost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, 
and that of right child is horizontal distance of x plus 1.

If there are multiple top-most nodes for a horizontal distance from root, then print the first one in level traversal.
*/

// Bottom view

vector <int> bottomView(Node *root)
{
  vector<int>ans;
  if(!root)
   return ans;
  map<int,int>mp;
  queue<pair<Node*,int>>q;
  int hd=0;
  q.push(make_pair(root,hd));
  while(!q.empty())
  {
    pair<Node*,int>temp=q.front();
    q.pop();
    Node* cur=temp.first;
    hd=temp.second;
    mp[hd]=cur->data;
    if(cur->left)
      q.push(make_pair(cur->left,hd-1));
    if(cur->right)
       q.push(make_pair(cur->right,hd+1));
  }
  for(auto xx:mp)
   ans.push_back(xx.second);
  return ans;
}


/*
A node x is there in output if x is the bottommost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, 
and that of right child is horizontal distance of x plus 1.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal.
*/

// Left view

//RECURSIVE

void printleftview(Node *root,int level,int *maxlevel)// first element of each level
{
    if(root==NULL)
     return;
    if(level>*maxlevel) // when level becomes greater than maxlevel then it is the first node of that level & that node is in left view.
    {
     cout<<root->data<<" ";
     *maxlevel=level;
    }
    // just flip below two statements then it becomes right view of BT
    printleftview(root->left,level+1,maxlevel);
    printleftview(root->right,level+1,maxlevel);
}
void leftView(Node *root)
{
  int maxlevel=0;
  printleftview(root,1,&maxlevel);

}

// ITERATIVE
queue<TreeNode*>q;// since left view is first element of each row
    q.push(root);
    while(!q.empty())
    {
     int zz=q.size();
     bool ff=1;
     for(int i=0;i<zz;i++)
     {
      TreeNode* cur=q.front();
      q.pop();
      if(ff)
         ans.push_back(cur->val),ff=0;
      if(cur->left)
          q.push(cur->left);
      if(cur->right)
          q.push(cur->right);
     }
    }
     return ans;

// Right View

//RECURSIVE

class Solution {
public:
    void doit(TreeNode* root,int level,int* maxlevel,vector<int>& ans)
    {
     if(!root)
         return;
     if(level>*maxlevel)
     {
      ans.push_back(root->val);
      *maxlevel=level;
     }
     doit(root->right,level+1,maxlevel,ans);
     doit(root->left,level+1,maxlevel,ans);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
     vector<int>ans;
     if(!root)  
         return ans;
     int maxlevel=0;
     doit(root,1,&maxlevel,ans);
     return ans;
     
    }
};

//ITERATIVE

 queue<TreeNode*>q;// since right view is last element of each row
    q.push(root);
    while(!q.empty())
    {
     int zz=q.size();
     bool ff=1;
     for(int i=0;i<zz;i++)
     {
      TreeNode* cur=q.front();
      q.pop();
      if(ff)
         ans.push_back(cur->val),ff=0;
      if(cur->right)
          q.push(cur->right);
      if(cur->left)
          q.push(cur->left);
     }
    }
     return ans;

// Diagonal Traversal

void doit(Node* root,int d,map<int,vector<int>>&mp)
{
 if(!root)
   return;
 mp[d].push_back(root->data); // Store all nodes of same line together as a vector 
 dt(root->left, d + 1,mp);  // Increase the vertical distance if left child 
 dt(root->right, d,mp); // Vertical distance remains same for right child
}

vector<int> Solution::solve(TreeNode* A) 
{
 vector<int>ans;
 map<int,vector<int>>mp;
 doit(A,0,mp);
 /*for (auto it = mp.begin(); 
         it != mp.end(); ++it) 
    { 
        for (auto itr = it->second.begin(); 
             itr != it->second.end(); ++itr) 
           ans.push_back(*itr); 
  
        //cout << 'n'; 
    } */
   for(auto xx:mp)
   {
    for(auto yy:xx.second)
    {
     ans.push_back(yy);
    }
   }
    
 return ans;
}

// Boundary Traversal

/*
1. Print the left boundary in top-down manner.
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
…..2.1 Print all leaf nodes of left sub-tree from left to right.
…..2.2 Print all leaf nodes of right subtree from left to right.
3. Print the right boundary in bottom-up manner.
*/


vector<int>vec;
void PrintBoundaryLeft(Node *root)
{
 if(root==NULL)
  return;
 if(root->left)
 {
  vec.push_back(root->data);
  PrintBoundaryLeft(root->left);
 }
 else if(root->right)
 {
  vec.push_back(root->data);
  PrintBoundaryLeft(root->right);
 }
}

void PrintBoundaryRight(Node *root)
{
 if(root==NULL)
  return;
 if(root->right)
 {
   vec.push_back(root->data);
   PrintBoundaryRight(root->right);
 }
 else if(root->left)
 {
  vec.push_back(root->data);
  PrintBoundaryRight(root->left);
 }

}

void PrintLeaf(Node *root)
{
 if(root==NULL)
  return;
 PrintLeaf(root->left);
 if(!root->left && !root->right)
  vec.push_back(root->data);
 PrintLeaf(root->right);
}

vector<int> printBoundary(Node *root)
{
 vec.clear();
 if(root==NULL)
  return vec;
 vec.push_back(root->data);
 PrintBoundaryLeft(root->left);
 PrintLeaf(root->left);
 PrintLeaf(root->right);
 PrintBoundaryRight(root->right);
 return vec;

}

// Diagonal Sum

void diagonalSumUtil(Node *root,int dd,map<int,int>&mp)
{
 if(root==NULL)
    return;

 diagonalSumUtil(root->left,dd+1,mp);
 diagonalSumUtil(root->right,dd,mp);
  mp[dd]+=root->data;
}


vector <int> diagonalSum(Node* root)
{
  vector<int>vv;
  map<int,int>mp;
 diagonalSumUtil(root,0,mp);

 map<int,int>::iterator itr;
 for(itr=mp.begin();itr!=mp.end();++itr)
    vv.push_back(itr->second);
 return vv;
}

// ZigZag Tree Traversal

// USING TWO STACKS
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
     vector<vector<int>>ans;
     if(!root)
         return ans;
     stack<TreeNode*>s1,s2;
     s1.push(root);
     while(!s1.empty() || !s2.empty())
     {
      vector<int>vv;
      while(!s1.empty())
      {
       TreeNode* cur=s1.top();
       s1.pop();
       vv.push_back(cur->val);
        if(cur->left)
           s2.push(cur->left);
       if(cur->right)
           s2.push(cur->right);
      
      }
      if(vv.size()>0)
       ans.push_back(vv);
      vv.clear();
      while(!s2.empty())
      {
       TreeNode* cur=s2.top();
       s2.pop();
       vv.push_back(cur->val);
       if(cur->right)
           s1.push(cur->right);
       if(cur->left)
           s1.push(cur->left);
      }
      if(vv.size()>0)
       ans.push_back(vv);
     }
     return ans;
        
    }
};

// USING ONLY ONE QUEUE

 queue<TreeNode*>q;
     q.push(root);
     bool ff=1;// ff=1(L-R) , ff=0(R-L)
     while(!q.empty())
     {
       int zz=q.size();
       vector<int>vv(zz);
       for(int i=0;i<zz;i++)
       {
        TreeNode *cur=q.front();
        q.pop();
        if(ff)
          vv[i]=cur->val;
        else
          vv[zz-i-1]=cur->val;
        if(cur->left)
            q.push(cur->left);     
        if(cur->right)
            q.push(cur->right);
       }
       ans.push_back(vv);
       ff=!ff;
      
     }
     return ans;
        
    }
};

// Spiral Traversal

void printSpiral(Node *root)
{

  stack<Node*>s1;
  stack<Node*>s2;
  s1.push(root);
  while(!s1.empty() || !s2.empty())
  {
    while(!s1.empty())
    {
     Node *temp=s1.top();
     s1.pop();
     cout<<temp->data<<" ";
     if(temp->right)
       s2.push(temp->right);
     if(temp->left)
       s2.push(temp->left);
    }
    while(!s2.empty())
    {
     Node *temp=s2.top();
     s2.pop();
     cout<<temp->data<<" ";
     if(temp->left)
       s1.push(temp->left);
     if(temp->right)
       s1.push(temp->right);
    }
  }
}

//  Right Sibling in Binary Tree

Node* findRightSibling(Node* node)
{
   if(node==NULL || node->parent==NULL)
    return NULL;
   if(node==node->parent->left && node->parent->right)
    return node->parent->right;
   Node *temp=findRightSibling(node->parent);
   if(temp && (temp->left || temp->right))
   {
     if(temp->left)
      return temp->left;
     else
      return temp->right;
   }
   else if(temp)
    return findRightSibling(node->parent);
}

