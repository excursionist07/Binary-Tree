int height(Node *root)
{
  if(root==NULL)
    return 0;
 int LH=height(root->left);
 int RH=height(root->right);
 return max(LH,RH)+1;
}
int diameter(Node* node)
{
  if(node==NULL)
    return 0;
 int left_ht=height(node->left);
 int right_ht=height(node->right);

 int left_dm=diameter(node->left);
 int right_dm=diameter(node->right);
 return max(1+left_ht+right_ht,max(left_dm,right_dm));//if count from node and if asked about from edge count just remove "1+" from this line

}
