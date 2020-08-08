void topView(struct Node *root)
{
  if(!root)
   return;
  map<int,int>mp;
  queue<pair<Node*,int>>q;
  int hd=0;
  q.push(make_pair(root,hd));
  while(!q.empty())
  {
    pair<Node*,int>temp=q.front();
    q.pop();
    Node* cur=temp.first;
    hd=temp.second;
    if(mp.count(hd)==0)
      mp[hd]=cur->data;
    if(cur->left)
      q.push(make_pair(cur->left,hd-1));
    if(cur->right)
       q.push(make_pair(cur->right,hd+1));
     
  }
  for(auto xx:mp)
   cout<<xx.second<<" ";
}




/*
A node x is there in output if x is the topmost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, 
and that of right child is horizontal distance of x plus 1.

If there are multiple top-most nodes for a horizontal distance from root, then print the first one in level traversal.
*/
