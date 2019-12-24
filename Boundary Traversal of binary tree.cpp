vector<int>vec;
void PrintBoundaryLeft(Node *root)
{
 if(root==NULL)
  return;
 if(root->left)
 {
  cout<<root->data<<" ";
  PrintBoundaryLeft(root->left);
 }
 else if(root->right)
 {
  cout<<root->data<<" ";
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
  cout<<root->data<<" ";
 PrintLeaf(root->right);
}

void printBoundary(Node *root)
{
 vec.clear();
 if(root==NULL)
  return;
 cout<<root->data<<" ";
 PrintBoundaryLeft(root->left);
 PrintLeaf(root->left);
 PrintLeaf(root->right);
 PrintBoundaryRight(root->right);
 for(int i=vec.size()-1;i>=0;i--)
  cout<<vec[i]<<" ";

}
