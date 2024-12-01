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
class Pair{
    public:
    int height;
    bool isBalanced;
};

Pair checkBalanced(node* root){
    //base
    if(!root){
        Pair p;
        p.height=0;
        p.isBalanced=true;
        return p;                   //check github

    }
    //recursi
    Pair left=checkBalanced(root->left);
    Pair right=checkBalanced(root->right);

    Pair p;
    p.height=max(left.height,right.height)+1 ;

    if(abs(left.height-right.height)<=1 and left.isBalanced and right.isBalanced){
        p.isBalanced=true;
    }

    else{
        p.isBalanced=false;
    }
    return p;

    }