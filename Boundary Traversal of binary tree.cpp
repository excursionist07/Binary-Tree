/*
1. Print the left boundary in top-down manner.
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
…..2.1 Print all leaf nodes of left sub-tree from left to right.
…..2.2 Print all leaf nodes of right subtree from left to right.
3. Print the right boundary in bottom-up manner.
*/


vector<int>vec;
void PrintBoundaryLeft(Node *root)
{
 if(root==NULL)
  return;
 if(root->left)
 {
  vec.push_back(root->data);
  PrintBoundaryLeft(root->left);
 }
 else if(root->right)
 {
  vec.push_back(root->data);
  PrintBoundaryLeft(root->right);
 }
}

void PrintBoundaryRight(Node *root)
{
 if(root==NULL)
  return;
 if(root->right)
 {
   vec.push_back(root->data);
   PrintBoundaryRight(root->right);
 }
 else if(root->left)
 {
  vec.push_back(root->data);
  PrintBoundaryRight(root->left);
 }

}

void PrintLeaf(Node *root)
{
 if(root==NULL)
  return;
 PrintLeaf(root->left);
 if(!root->left && !root->right)
  vec.push_back(root->data);
 PrintLeaf(root->right);
}

vector<int> printBoundary(Node *root)
{
 vec.clear();
 if(root==NULL)
  return vec;
 vec.push_back(root->data);
 PrintBoundaryLeft(root->left);
 PrintLeaf(root->left);
 PrintLeaf(root->right);
 PrintBoundaryRight(root->right);
 return vec;

}
