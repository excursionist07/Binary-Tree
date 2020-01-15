void makeparent(Node *root,int parent[])
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

int kthAncestor(Node *root, int k, int node)
{
 if(k==0 || !root)
  return -1;
 int parent[10204];
 makeparent(root,parent);
 int cnt=0;
 while(node!=-1)
 {
   node=parent[node];
   cnt++;
   if(cnt==k)
    break;
 }
 return node;
}
