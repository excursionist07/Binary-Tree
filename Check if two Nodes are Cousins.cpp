bool isCousins(Node *root, int a, int b)
{
  if(!root || a==b)
   return true;
  queue<Node*>q;
  q.push(root);
  while(!q.empty())
  {
   int cnt=0,zz=q.size();
   for(int i=0;i<zz;i++)
   {
    Node* cur=q.front();
    q.pop(); 
    if(cur->left && (cur->left->data==a || cur->left->data==b))
     cnt++;
    else if(cur->right && (cur->right->data==a || cur->right->data==b))
     cnt++;
    if(cur->left)
     q.push(cur->left);
    if(cur->right)
     q.push(cur->right);
   
   }
    if(cnt==2)
     return true;
  }
  return false;
}
