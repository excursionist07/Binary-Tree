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
