//node class is same as is preorder inorder and postorder and levelorder
//complete
#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int data;
    node (int d){
        data=d;
        left=right=NULL;
    }
};
void PreOrder(node* root){
    //base case
    if(!root){
        return;
    }

    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void Inorder(node*root){
    if(!root){
    return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void postOrder(node*root){
    if(!root){
    return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}