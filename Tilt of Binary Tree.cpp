/*
The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
The tilt of the whole tree is defined as the sum of all nodes' tilt.----VERY IMPORTANT,it should not be misunderstood just to find abs(LS-RS) ONLY.
*/

int sum(Node *root)
{
 if(root==NULL)
  return 0;
 return sum(root->left)+root->val+sum(root->right);
}
int tiltTree(Node* root)
{

 if(root==NULL)
  return 0;

 int LS=sum(root->left);
 int RS=sum(root->right);
 return abs(LS-RS)+tiltTree(root->left)+tiltTree(root->right);

}
