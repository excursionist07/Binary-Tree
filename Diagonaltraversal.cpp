

void dt(Node* root,int d,map<int,vector<int>>&mp)
{
 if(!root)
   return;
 mp[d].push_back(root->data); // Store all nodes of same line together as a vector 
 dt(root->left, d + 1,mp);  // Increase the vertical distance if left child 
 dt(root->right, d,mp); // Vertical distance remains same for right child
}

vector<int> Solution::solve(TreeNode* A) 
{
 vector<int>ans;
 map<int,vector<int>>mp;
 doit(A,0,mp);
 /*for (auto it = mp.begin(); 
         it != mp.end(); ++it) 
    { 
        for (auto itr = it->second.begin(); 
             itr != it->second.end(); ++itr) 
           ans.push_back(*itr); 
  
        //cout << 'n'; 
    } */
   for(auto xx:mp)
   {
    for(auto yy:xx.second)
    {
     ans.push_back(yy);
    }
   }
    
 return ans;
}
