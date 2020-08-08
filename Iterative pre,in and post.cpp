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

void postOrder(Node* root) // USING TWO STACKS ,first do DRL
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

