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
int height(node * root){
    if(!root){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;

}

bool isBalancedBST(node* root){
    //base
    if(!root){
        return true;
    }
    //recur
    int h1=height(root->left);
    int h2=height(root->right);
    if(abs(h1-h2)<=1 and isBalancedBST(root->left) and isBalancedBST(root->right)){
        return true;
    }
    return false;
}

