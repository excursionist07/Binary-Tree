bool isCousins(Node *root, int x, int y)
{
 if(root==NULL || x==y)
  return true;

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
     if(cur->left && (cur->left->data==x || cur->left->data==y))
      cnt++;
     else if(cur->right  && (cur->right->data==x || cur->right->data==y))
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
