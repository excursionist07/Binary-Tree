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
