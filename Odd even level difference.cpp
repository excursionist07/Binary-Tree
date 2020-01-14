int getLevelDiff(Node *root)
{
  int even=0,odd=0,ff=0;
  queue<Node*>q;
  q.push(root);
  while(!q.empty())
  {
    int zz=q.size();
    if(ff==0)
    {
     for(int i=0;i<zz;i++)
     {
      Node *cur=q.front();
      q.pop();
      odd+=(cur->data);
      if(cur->left)
        q.push(cur->left);
      if(cur->right)
        q.push(cur->right);
     }
     ff=1;
    }
    else if(ff==1)
    {
     for(int i=0;i<zz;i++)
     {
      Node *cur=q.front();
      q.pop();
      even+=cur->data;
     if(cur->left)
        q.push(cur->left);
      if(cur->right)
        q.push(cur->right);
     }
     ff=0;
    }
  }
  return (odd-even);

  // SECOND METHOD
 /* if(root==NULL)
   return 0;
  return root->data-getLevelDiff(root->left)-getLevelDiff(root->right);*/
}

