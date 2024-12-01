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
void printRange(node* root,int k1,int k2){
    //base
    if(!root){
        return;
    }   

    printRange(root->left,k1,k2);

    if(root->data>=k1 and root->data<=k2){
        cout<<root->data<<" ";
    }
    printRange(root->right,k1,k2);

}