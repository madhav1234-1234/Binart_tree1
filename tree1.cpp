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

void inorder(Node *root)
{
    if(root==NULL){
        return;
    }
    else{
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(Node *root){
    if(root==NULL){
        return;
    }
    else{
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root){
    if(root==NULL){
        return;
    }else{
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
// iterative
void levelorder(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
       int count=q.size();
       for(int i=0;i<count;i++){
         Node *u=q.front();
         q.pop();
         cout<<u->data<<" ";
         if(u->left!=NULL){
           q.push(u->left);
         }
         if(u->right!=NULL){
           q.push(u->right);
         }
       }
    }  
}

// Recursive
int height(Node *root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
void printK(Node *root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printK(root->left,k-1);
    printK(root->right,k-1);
}
void printLevel(Node *root){
    if(root==NULL){
        return;
    }
    int count=height(root);
    for(int i=0;i<count;i++){
        printK(root,i);
    }

}

// left view (recursive)
void left(Node *root,int level,int *maxlevel){
    if(root==NULL){
        return;
    }
    if(*maxlevel<level){
       cout<<root->data<<" ";
       *maxlevel=level;
    }
    left(root->left,level+1,maxlevel);
    left(root->right,level+1,maxlevel);
}
// left view(iterative)
void leftv(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        for(int i=0;i<count;i++){
            Node *curr=q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

// right view (recursive)
void right(Node *root,int level,int *maxlevel){
    if(root==NULL){
        return;
    }
    if(*maxlevel<level){
       cout<<root->data<<" ";
       *maxlevel=level;
    }
    right(root->right,level+1,maxlevel);
    right(root->left,level+1,maxlevel);
}
// right view(iterative)
void rightv(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        for(int i=0;i<count;i++){
            Node *curr=q.front();
            q.pop();
            if(i==count-1){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
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
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;
    cout<<height(root);
    cout<<endl;
    printLevel(root);   
    cout<<endl;
    int maxlevel=0;
    left(root,1,&maxlevel);     
    cout<<endl;
    leftv(root);
    cout<<endl;
    maxlevel=0;
    right(root,1,&maxlevel);     
    cout<<endl;
    rightv(root);
}
