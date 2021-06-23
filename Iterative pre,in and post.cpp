void preorder(Node* root)
{
  stack<Node*>stk;
  stk.push(root);
  while(!stk.empty()) // --> we do DRL for it
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

void postOrder(Node* root) // USING TWO STACKS ,first do DLR
{
 if(root==NULL)
  return;
 stack<Node*>s1,s2;
 s1.push(root); 
 while(!s1.empty())
 {
  Node *cur=s1.top();
  s1.pop();
  s2.push(cur); // whie printing push it in other stack
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

// 589. N-ary Tree Preorder Traversal

class Solution {
public:
    void doit(Node* root,vector<int>& vv)
    {
     if(!root)
         return;
     vv.push_back(root->val);
     for(auto xx:root->children)
         doit(xx,vv);
     
    }
    vector<int> preorder(Node* root)
    {
     if(!root)
         return {};
     vector<int>vv;
     doit(root,vv);
     return vv;
    }
};

// 590. N-ary Tree Postorder Traversal

class Solution {
public:
    void doit(Node* root,vector<int>& vv)
    {
     if(!root)
         return;
     for(auto xx:root->children)
         doit(xx,vv);
     vv.push_back(root->val);
    }
    vector<int> postorder(Node* root)
    {
     if(!root)
         return {};
     vector<int>vv;
     doit(root,vv);
     return vv;
    }
};

// 429. N-ary Tree Level Order Traversal

class Solution {
public:
    void doit(vector<vector<int>>& ans,Node* root)
    {
     queue<Node*>q;
     q.push(root);
     while(!q.empty())
     {
      int zz=q.size();
      vector<int>vv;
      while(zz--)
      {
       Node* cur=q.front();
       q.pop();
       vv.push_back(cur->val);
       for(auto xx:cur->children)
           q.push(xx);
      }
      ans.push_back(vv);
     }
    }
    vector<vector<int>> levelOrder(Node* root)
    {
      vector<vector<int>>ans;
      if(!root)
          return ans;
      doit(ans,root);
      return ans;
      
          
    }
};

// 559. Maximum Depth of N-ary Tree


class Solution {
public:
    // -->RECURSIVE
  
    int doit(Node* root)
    {
     if(!root)
         return 0;
     else
     {
      int depth=0;   
      for(auto xx:root->children)
          depth=max(depth,doit(xx));
      return (1+depth);
     }
    }
    // --> ITERATIVE
  
    // int doit1(Node* root)
    // {
    //  queue<Node*>q;
    //  q.push(root);
    //  int ans=0;
    //  while(!q.empty())
    //  {
    //   int zz=q.size();
    //   while(zz--)
    //   {
    //    Node* cur=q.front();
    //    q.pop();
    //    for(auto xx:cur->children)
    //        q.push(xx);
    //   }
    //   ans++;
    //  }
    //  return ans;
    // }
    
    int maxDepth(Node* root) 
    {
     if(!root)
         return 0;
     return doit(root);
    }
};
