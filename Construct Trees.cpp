 // Construct Tree from inorder and preorder

class Solution {
public:
    int search(vector<int>& inorder,int start,int end,int x)
    {
     int i;
     for(i=start;i<=end;i++)
     {
      if(inorder[i]==x)
        break;
     }
     return i;
    }
    TreeNode* doit(vector<int>& preorder,vector<int>& inorder,int start,int end,int& idx)
    {
     if(start>end)
         return NULL;
     TreeNode* temp=new TreeNode(preorder[idx++]);
     if(start==end)
         return temp;
     int zz=search(inorder,start,end,temp->val);
     temp->left=doit(preorder,inorder,start,zz-1,idx);
     temp->right=doit(preorder,inorder,zz+1,end,idx);
     return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
     int n=preorder.size();
     int idx=0;
     return doit(preorder,inorder,0,n-1,idx);
     
    }
};

// Construct Tree from inorde and postorder

class Solution {
public:
    int search(vector<int>& inorder,int start,int end,int x)
    {
     int i;
     for(i=start;i<=end;i++)
     {
      if(inorder[i]==x)
          break;
     }
     return i;
    }
    TreeNode* doit(vector<int>& inorder,vector<int>& postorder,int start,int end,int& idx)
    {
     if(start>end)
         return NULL;
     TreeNode* temp=new TreeNode(postorder[idx--]);
     if(start==end)
         return temp;
     int zz=search(inorder,start,end,temp->val);
     temp->right=doit(inorder,postorder,zz+1,end,idx);
     temp->left=doit(inorder,postorder,start,zz-1,idx);
     return temp;
     
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
     int n=inorder.size();
     int idx=n-1;
     return doit(inorder,postorder,0,n-1,idx);
    }
};

// Construct Trees from Preorder and Postorder



class Solution {
public:
    int preIndex=0,postIndex=0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
    {
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if (root->val != post[postIndex])
            root->left = constructFromPrePost(pre, post);
        if (root->val != post[postIndex])
            root->right = constructFromPrePost(pre, post);
        postIndex++;
        return root;

    }
};

// Postorder traversal from given Inorder and Preorder traversals

int preindex;
struct Node
{
 int data;
 Node *left;
 Node *right;
};

Node *GetNewNode(int x)
{
 Node *temp=new Node();
 temp->data=x;
 temp->left=temp->right=NULL;
 return temp;
}
int search(int in[],int start,int end,int zz)
{
 for(int i=start;i<=end;i++)
 {
    if(in[i]==zz)
     return i;
 }
}
Node *buildtree(int in[],int pre[],int strt,int end)
{
 if(strt>end)
  return NULL;
 Node* temp=GetNewNode(pre[preindex++]);

 if(strt==end)
  return temp;
 int zz=search(in,strt,end,temp->data);
 temp->left=buildtree(in,pre,strt,zz-1);
 temp->right=buildtree(in,pre,zz+1,end);
 return temp;


}
void postorder(Node *temp)
{
 if(temp==NULL)
  return;
 postorder(temp->left);
 postorder(temp->right);
 cout<<temp->data<<" ";
}
void printPostOrder(int in[], int pre[], int n)
{
  preindex=0;
  Node *temp=buildtree(in,pre,0,n-1);
  postorder(temp);
  //cout<<"\n";
}

// Construct Binary Tree from Parent Array

//RECURSIVE

void CreateNode(int parent[],int i,Node *created[],Node **root)
{
 if(created[i])
   return;
 created[i]=new Node(i);
 if(parent[i]==-1)
 {
  *root=created[i];
  return;
 }
 if(created[parent[i]]==NULL)
    CreateNode(parent,parent[i],created,root);
 //created[i]=GetNewNode(i);
 Node *zz=created[parent[i]];
 if(zz->left==NULL)
  zz->left=created[i];
 else
  zz->right=created[i];

}

Node *createTree(int parent[], int n)
{
  Node *created[n];
  for(int i=0;i<n;i++)
    created[i]=NULL;
  Node *root=NULL;
  for(int i=0;i<n;i++)
  {
   CreateNode(parent,i,created,&root);
  }
  return root;
}

// ITERATIVE


Node *createTree(int parent[], int n)
{
  map<int,vector<int>>mp;
  for(int i=0;i<n;i++)
   mp[parent[i]].push_back(i);
  if(mp[-1].size()==0)// no root present
   return NULL;
  queue<Node*>q;
  Node *root=NULL;
  q.push(new Node(mp[-1][0]));
  while(!q.empty())
  {
    Node* temp=q.front();
    q.pop();
    if(!root)
     root=temp;
    int zz=temp->data;
    if(mp[zz].size()>0)
    {
     temp->left=new Node(mp[zz][0]);
     q.push(temp->left);
     if(mp[zz].size()>1)
     {
      temp->right=new Node(mp[zz][1]);
      q.push(temp->right);
     }
    }
  }
  return root;
}

// Construct Complete Binary Tree from its LL

void convert(Node *head, TreeNode *&root) 
{
 if(!head)
 {
    root=NULL;
    return;
 }
 root=new TreeNode(head->data);
 head=head->next;
 queue<TreeNode*>q;
 q.push(root);
 while(head)
 {
  TreeNode* cur=q.front();
  q.pop();
  cur->left=new TreeNode(head->data);
  head=head->next;
  q.push(cur->left);
  if(head)
  {
    cur->right=new TreeNode(head->data);
    q.push(cur->right);
    head=head->next;
  }
 }
 
}
