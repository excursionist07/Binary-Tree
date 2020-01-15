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
