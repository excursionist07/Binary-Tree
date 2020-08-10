

class Solution {
public:
    Node* connect(Node* root) // for all
    {
     if(!root)
         return NULL;
     /*queue<Node*>q; //O(n) space and O(n) time
     q.push(root);
     q.push(NULL);
     while(!q.empty())
     {
      Node *cur=q.front();
      q.pop();
      if(cur)
      {
       cur->next=q.front();
       if(cur->left)
           q.push(cur->left);
       if(cur->right)
           q.push(cur->right);
      }
      else if(!q.empty())
          q.push(NULL);
     }*/
    
        
    // Initially, all next pointers are set to NULL.
    /*Node *pre=root;
    Node *cur=NULL;//O(n) && O(1)  itrrative ,if tree is perfect binary tree
   while(pre->left)// Outer loop for each level ,standing on level i we connect level (i+1)
    {
     cur=pre;
     while(cur)
     {
      cur->left->next=cur->right;
      if(cur->next)
          cur->right->next=cur->next->left;
      cur=cur->next;
     }
     pre=pre->left;
    }*/

        //recursive O(n) && O(1)

        if (root->left) root->left->next = root->right;
        if (root->right && root->next) root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);

     return root;
    }
};
