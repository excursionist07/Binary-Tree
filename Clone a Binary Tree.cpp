Node* cloneTree(Node* tree)
{
  if(!tree)
   return NULL;
  Node* temp=new Node(tree->data);
  temp->random=tree->random;
  temp->left=cloneTree(tree->left);
  temp->right=cloneTree(tree->right);
  return temp;
  
}

// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree


class Solution {
public:
    TreeNode* ans;
    void doit(TreeNode* original,TreeNode* cloned,TreeNode* target)
    {
     if(!original)
        return;
     if(original==target)
     {
      ans=cloned;
      return;
     }
     doit(original->left,cloned->left,target);
     doit(original->right,cloned->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
     if(!original)
         return NULL;
     doit(original,cloned,target);
     return ans;
     
    }
};
