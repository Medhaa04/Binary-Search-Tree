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
node* buildBalancedBST(int a[],int s,int e){
    //base
    if(s>e){
        return NULL;
    }

    //recursive
    int m=(s+e)/2;
    node* root=new node(a[m]);
    root->left=buildBalancedBST(a,s,m-1);
    root->right=buildBalancedBST(a,m+1,e);
    return root;
}

