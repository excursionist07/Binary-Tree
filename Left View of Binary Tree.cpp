//RECURSIVE

void printleftview(Node *root,int level,int *maxlevel)// first element of each level
{
    if(root==NULL)
     return;
    if(level>*maxlevel) // when level becomes greater than maxlevel then it is the first node of that level & that node is in left view.
    {
     cout<<root->data<<" ";
     *maxlevel=level;
    }
    // just flip below two statements then it becomes right view of BT
    printleftview(root->left,level+1,maxlevel);
    printleftview(root->right,level+1,maxlevel);
}
void leftView(Node *root)
{
  int maxlevel=0;
  printleftview(root,1,&maxlevel);

}

// ITERATIVE
queue<TreeNode*>q;// since left view is first element of each row
    q.push(root);
    while(!q.empty())
    {
     int zz=q.size();
     bool ff=1;
     for(int i=0;i<zz;i++)
     {
      TreeNode* cur=q.front();
      q.pop();
      if(ff)
         ans.push_back(cur->val),ff=0;
      if(cur->left)
          q.push(cur->left);
      if(cur->right)
          q.push(cur->right);
     }
    }
     return ans;
