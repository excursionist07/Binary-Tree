int getLevelDiff(Node *root)
{
  if(!root)
   return 0;
  int odd=0,even=0;
  queue<Node*>q;
  q.push(root);
  bool ff=1;
  while(!q.empty())
  {
   int n=q.size();
   int sum=0;
   for(int i=0;i<n;i++)
   {
     Node* cur=q.front();
     q.pop();
     sum+=cur->data;
     if(cur->left)
      q.push(cur->left);
     if(cur->right)
      q.push(cur->right);
   }
   if(ff)
    odd+=sum;
   else
    even+=sum;
   ff=!ff;
  }
  return odd-even;
  
}

