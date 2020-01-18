int convert(Node *node)
{
  if(node==NULL)
   return 0;

  int old=node->data;
  node->data=convert(node->left)+convert(node->right);
  return node->data+old;
}
void toSumTree(Node *node)
{
  if(node==NULL)
   return;
  convert(node);

}
