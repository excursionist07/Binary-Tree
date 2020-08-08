vector<int> verticalOrder(Node *root)
{
   vector<int>ans;
     if(!root)
         return ans;
     map<int,vector<int>>mp;
     queue<pair<Node*,int>>q;
     int hd=0;
     q.push(make_pair(root,hd));
     while(!q.empty())
     {
      pair<Node*,int>temp=q.front();
      q.pop();
      Node* cur=temp.first;
      hd=temp.second;
      mp[hd].push_back(cur->data);
      if(cur->left)
          q.push(make_pair(cur->left,hd-1));
      if(cur->right)
          q.push(make_pair(cur->right,hd+1));

     }
     for(auto xx:mp)
     {

      for(auto yy:xx.second)
      {
       ans.push_back(yy);
      }

     }

     return ans;
}


