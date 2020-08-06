void diagonalSumUtil(Node *root,int dd,map<int,int>&mp)
{
 if(root==NULL)
    return;

 diagonalSumUtil(root->left,dd+1,mp);
 diagonalSumUtil(root->right,dd,mp);
  mp[dd]+=root->data;
}


vector <int> diagonalSum(Node* root)
{
  vector<int>vv;
  map<int,int>mp;
 diagonalSumUtil(root,0,mp);

 map<int,int>::iterator itr;
 for(itr=mp.begin();itr!=mp.end();++itr)
    vv.push_back(itr->second);
 return vv;
}
