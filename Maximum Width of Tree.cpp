// Width of a tree is maximum of widths of all levels, means max. no. of nodes in all levels.

int getMaxWidth(Node* root)
{
  if(root==NULL)
   return 0;
  queue<Node*>q;
  q.push(root);
  int maxx=INT_MIN;
  while(!q.empty())
  {
    int zz=q.size();
    maxx=max(maxx,zz);
    for(int i=0;i<zz;i++)
    {
     Node *cur=q.front();
     q.pop();
     if(cur->left)
      q.push(cur->left);
     if(cur->right)
      q.push(cur->right);
    }
  }
  return maxx;
}
