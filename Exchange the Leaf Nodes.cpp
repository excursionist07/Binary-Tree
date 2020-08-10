
// O(n) space
/*void doit(Node *root,vector<Node*>&vec)
{
 if(!root)
  return;
 if(!root->left && !root->right)
  vec.push_back(root);
 if(root->left)
  doit(root->left,vec);
 if(root->right)
  doit(root->right,vec);
}*/

// o(1) space
void doit1(Node* root,Node*  &temp)
{
 if(!root)
  return;
 if(!root->left && !root->right)
 {
  if(temp)
  {
    swap(temp->data,root->data);
    temp=NULL;
  }
  else
   temp=root;
 }
 doit1(root->left,temp);
 doit1(root->right,temp);

}
void pairwiseSwap(Node *root)
{
  /*vector<Node*>vec;
  doit(root,vec);
  int size=(vec.size()%2==0) ? vec.size():vec.size()-1;
  for(int i=0;i<size;i+=2)
   swap(vec[i]->data,vec[i+1]->data);*/
   Node *temp=NULL;
   doit1(root,temp);
}
