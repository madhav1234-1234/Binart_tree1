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

void printLeaves(Node *root){
    if(root==NULL){
        return ;
    }
    printLeaves(root->left);
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }
    printLeaves(root->right);
}
void boundryTraversalLeft(Node *root)
{
    if(root==NULL){
        return ;
    }
    if(root->left!=NULL){
        cout<<root->data<<" ";
        boundryTraversalLeft(root->left);
    }
    else if(root->right!=NULL){
        cout<<root->data<<" ";
        boundryTraversalLeft(root->right);
    }
}

void boundryTraversalright(Node *root)
{
    if(root==NULL){
        return ;
    }
    if(root->right!=NULL){
        boundryTraversalright(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left!=NULL){
        boundryTraversalright(root->left);
        cout<<root->data<<" ";
    }
}

void boundryTraversal(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    boundryTraversalLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    boundryTraversalright(root->right);
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
    boundryTraversal(root);
    
  
}
