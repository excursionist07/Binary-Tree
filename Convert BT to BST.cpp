void in1(Node* root,vector<int>&vv)
{
 if(!root)
  return;
 in1(root->left,vv);
 vv.push_back(root->data);
 in1(root->right,vv);
}

Node* in2(Node* root,vector<int>&vv,int &idx)
{
 if(!root)
  return NULL;
 in2(root->left,vv,idx);
 root->data=vv[idx++];
 in2(root->right,vv,idx);
 return root;
}
Node *binaryTreeToBST (Node *root)
{
   if(!root)
    return NULL;
   vector<int>vv;
   in1(root,vv);
   sort(vv.begin(),vv.end());
   int idx=0;
   Node* temp=in2(root,vv,idx);
   return temp;
}
