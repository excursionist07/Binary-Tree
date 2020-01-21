set<Node*>s;
void countNode(Node* root, int k,vector<Node*>vec)
{
 if(!root)
  return;
 vec.push_back(root);
 if(!root->left && !root->right && vec.size()>k)
  s.insert(vec[vec.size()-k-1]);
 countNode(root->left,k,vec);
 countNode(root->right,k,vec);
}
int printKDistantfromLeaf(Node* node, int k)
{
 s.clear();
 vector<Node*>vec;
 countNode(node,k,vec);
 return s.size();

}
