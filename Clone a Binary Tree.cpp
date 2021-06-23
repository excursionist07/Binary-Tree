// Clone a Binary Tree 

class Solution{
  public:
    /* The function should clone the passed tree and return 
       root of the cloned tree */
  
    Node* doit(Node* tree,unordered_map<Node*,Node*>&mp) // traversing in original tree
    {
     if(!tree)
      return NULL;
     Node* cur=new Node(tree->data);
     mp[tree]=cur;
     cur->left=doit(tree->left,mp);
     cur->right=doit(tree->right,mp);
     return cur;
    }
  
    void RandomPointer(Node* tree,Node* clonedRoot,unordered_map<Node*,Node*>&mp) // // traversing in cloned tree
    {
     if(!clonedRoot)
       return;
     clonedRoot->random=mp[tree->random];
     RandomPointer(tree->left,clonedRoot->left,mp);
     RandomPointer(tree->right,clonedRoot->right,mp);
     
    }
  
    Node* cloneTree(Node* tree)
    {
     if(!tree)return NULL;
     unordered_map<Node*,Node*>mp;
     Node* clonedRoot=doit(tree,mp);
     RandomPointer(tree,clonedRoot,mp);
     return clonedRoot;
    }
};

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
