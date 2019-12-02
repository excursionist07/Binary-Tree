Node* lca(Node* root,int a,int b)
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
int dist(Node* root,int a)
{
 if(root==NULL)
  return 0;
 if(root->data==a)
   return 0;
 return 1+min(dist(root->left,a),dist(root->right,a));
}
int findDist(Node* root, int a, int b)
{
   Node* LCA=lca(root,a,b);
   return dist(LCA,a)+dist(LCA,b);
}
