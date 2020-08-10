void convert(Node *head, TreeNode *&root) 
{
 if(!head)
 {
    root=NULL;
    return;
 }
 root=new TreeNode(head->data);
 head=head->next;
 queue<TreeNode*>q;
 q.push(root);
 while(head)
 {
  TreeNode* cur=q.front();
  q.pop();
  cur->left=new TreeNode(head->data);
  head=head->next;
  q.push(cur->left);
  if(head)
  {
    cur->right=new TreeNode(head->data);
    q.push(cur->right);
    head=head->next;
  }
 }
 
}
