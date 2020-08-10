
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   /* int distance(TreeNode* root,TreeNode* target)
    {
     if(!root)
         return 0;
     else if(root->val==target->val)
         return 0;
     else
         return 1+min(distance(root->left),distance(root->right));
    }*/
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
