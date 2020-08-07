Method 1 (By Storing root to n1 and root to n2 paths):
Following is simple O(n) algorithm to find LCA of n1 and n2.
1) Find path from root to n1 and store it in a vector or array.
2) Find path from root to n2 and store it in another vector or array.
3) Traverse both paths till the values in arrays are same. Return the common element just before the mismatch.

  
Node* lca(Node* root,int a,int b) //O(n) && O(1)
{
 if(root==NULL)
  return NULL;
 if(root->data==a || root->data==b)
   return root;
 Node* l=lca(root->left,a,b);
 Node* r=lca(root->right,a,b);
 if(l && r)return root;
 if(!l && !r)return NULL;
 if(l) return l;
 if(r) return r;
  
}
