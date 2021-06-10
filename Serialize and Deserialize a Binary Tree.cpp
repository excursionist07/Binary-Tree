// gfg --> Serialize and Deserialize BT

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
 
    void preorder(Node* root,vector<int>& vv)
    {
     if(!root)
     {
      vv.push_back(-1);
      return;
     }
     vv.push_back(root->data);
     preorder(root->left,vv);
     preorder(root->right,vv);
    }
    
    vector<int> serialize(Node *root) 
    {
      if(!root)return {};
      vector<int>vv;
      preorder(root,vv);
      return vv;
    }
    
    //Function to deserialize a list and construct the tree.
 
    Node* doit(vector<int>& A,int& idx)
    {
     if(idx==A.size()-1 || A[idx]==-1)
     {
      idx++;
      return NULL;
     }
     Node* cur=new Node(A[idx]);
     idx++;
     cur->left=doit(A,idx);
     cur->right=doit(A,idx);
     return cur;
    }
    Node * deSerialize(vector<int> &A)
    {
      if(A.size()==0)return NULL;
      int idx=0;
      return doit(A,idx);
    }

};

// 449. Serialize and Deserialize BST


class Codec {
public:

    
    void preorder(TreeNode* root,string& str)
    {
     if(!root)
       return;
     str+=to_string(root->val) + ",";
     preorder(root->left,str);
     preorder(root->right,str);
    }
    
    string serialize(TreeNode* root)
    {
     if(!root)return " ";
     string str="";
     preorder(root,str);
     return str;
    
    }

    // Decodes your encoded data to tree.
    int go(string& data,int& pos)
    {
     pos=data.find(',');
     int value=stoi(data.substr(0,pos));
     return value;
    }
    TreeNode* doit(string& data,int mn,int mx)
    {
     if(!data.length())return NULL;
     int pos=0;
     int value=go(data,pos);
     if(value<mn || value>mx)return NULL;
     data=data.substr(pos+1);// after using number delete the used & this statement should be below upper statement b'coz in recursion it is needed
     
     TreeNode* cur=new TreeNode(value);
     cur->left=doit(data,mn,cur->val);
     cur->right=doit(data,cur->val,mx);
     return cur;
    }
    
    TreeNode* deserialize(string data)
    {
      if(data==" ")return NULL;
      return doit(data,INT_MIN,INT_MAX);
      
    }
};

// 297. Serialize and Deserialize Binary Tree


class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode* root,string& str)
    {
     if(!root)
     {
      str+="#";
      str+=",";
      return;
     }
     str+=to_string(root->val)+",";
     preorder(root->left,str);
     preorder(root->right,str);
    }
    string serialize(TreeNode* root) 
    {
     if(!root)return "#";
     string str="";
     preorder(root,str);
     return str; // (str =1,2,#,#,3,4,#,#,5,#,#,) foor Example 1.
    }

    // Decodes your encoded data to tree.
    int go(string& data,int& pos)
    {
     pos=data.find(',');
     int value=stoi(data.substr(0,pos));
     return value;
    }
    
    TreeNode* doit(string& data)
    {
     if(data[0]=='#') // it means NULL
     {
       if(data.length()>1)
           data=data.substr(2); // eleminating '#' and ',' from data
       return NULL;
     }
     int pos=0;
     int value=go(data,pos);
     data=data.substr(pos+1);
     TreeNode* cur=new TreeNode(value);
     cur->left=doit(data);
     cur->right=doit(data);
     return cur;
    }
    TreeNode* deserialize(string data) 
    {
     return doit(data);
    }
};



