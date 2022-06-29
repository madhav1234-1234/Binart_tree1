#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
   int data;
   Node *left;
   Node *right;
   Node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
   }
};

void spiral(Node *root)
{
    if(root==NULL){
        return;
    }
    stack<Node*>s1,s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
      while(!s1.empty()){
         Node *curr=s1.top();
        s1.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            s2.push(curr->left);
        }
        if(curr->right!=NULL){
            s2.push(curr->right);
        }
      }  
    while(!s2.empty()){
        Node *curr=s2.top();
        s2.pop();
        cout<<curr->data<<" ";
        if(curr->right!=NULL){
            s1.push(curr->right);
        }
        if(curr->left!=NULL){
            s2.push(curr->left);
        }
    }

    }

}

bool isIdentical(Node *root,Node *root1)
{
    if(root==NULL && root1==NULL){
        return true;
    }
    if(root!=NULL && root!=NULL){
        return (root->data==root1->data)&&isIdentical(root->left,root1->left)&&isIdentical(root->right,root1->right);
    }
}
int diameter(Node *root,int *res){
     if(root==NULL){
        return 0;
     }
     int lh=diameter(root->left,res);
     int rh=diameter(root->right,res);
     *res=max(*res,1+lh+rh);
     return max(lh,rh)+1;
}
bool isSymmetric(Node *root,Node *root1){
    if(root==NULL && root1==NULL){
        return true;
    }
    if(root!=NULL && root!=NULL){
        return (root->data==root1->data)&&isIdentical(root->left,root1->right)&&isIdentical(root->right,root1->left);
    }

}
int maxWidth(Node *root){
    if(root==NULL){
        return 0;
    }
    queue<Node*>q;
    q.push(root);
    int res=0;
    while(!q.empty()){
        int count=q.size();
        res=max(res,count);
        for(int i=0;i<count;i++){
            Node *curr=q.front();
            q.pop();
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
    return res;
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right->right=new Node(60);
    
    Node* root1 = new Node(10);
    root1->left = new Node(20);
    root1->right = new Node(30);
    root1->left->left = new Node(40);
    root1->left->right = new Node(50);
    root1->left->right->left = new Node(70);
    root1->left->right->right = new Node(80);
    root1->right->right=new Node(60);
    
    spiral(root);
    cout<<endl;
    int ans=isIdentical(root,root1);
    cout<<ans;
    cout<<endl;
    int res=0;
    diameter(root,&res);
    cout<<res;
    cout<<endl;
    cout<<isSymmetric(root,root1);
    cout<<endl;
    cout<<maxWidth(root);
}
