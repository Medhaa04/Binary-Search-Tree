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
node* searchInBST(node* root,int key){
    //base
    if(!root){
        return NULL;
    }
    //recur
    if(root->data==key){
        return root;                         
    }
    else if(root->data >key){
        return searchInBST(root->left,key);
    }
    else{
        return searchInBST(root->right,key);
    }
}
 