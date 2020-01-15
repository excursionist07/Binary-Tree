void makeparents(Node *root,int parent[])
{
 parent[root->data]=-1;
 queue<Node*>q;
 q.push(root);
 while(!q.empty())
 {
  Node *cur=q.front();
  q.pop();
  if(cur->left)
  {
    parent[cur->left->data]=cur->data;
    q.push(cur->left);
  }
  if(cur->right)
  {
    parent[cur->right->data]=cur->data;
    q.push(cur->right);
  }
 }

}
bool isCousins(Node *root, int x, int y)
{
 if(root==NULL || x==y)
  return 0;
 int parent[1007]={0};
 makeparents(root,parent);
 queue<Node*>q;
 q.push(root);
 while(!q.empty())
 {
   int zz=q.size();
   int cnt=0;
   for(int i=0;i<zz;i++)
   {
     Node* cur=q.front();
     q.pop();
     if(cur->data==x || cur->data==y)
      cnt++;
     if(cur->left)
      q.push(cur->left);
     if(cur->right)
      q.push(cur->right);
   }
   if(cnt==2)
   {
     if(parent[x]!=parent[y])
      return true;
     else
      return false;
   }
   else if(cnt==1)
    return false;
 }
 //return false;
}
