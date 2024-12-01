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
//BST TO LL
class LinkedList{
    public:
    node* head,*tail;
    LinkedList(){
        head=tail=NULL;
    }

};

LinkedList BSTtoLL(node* root){
    LinkedList l;
    //base
    if(!root){
        return l;
    }

    //recursive
    if(root->left and root->right){
        LinkedList left=BSTtoLL(root->left);
        LinkedList right=BSTtoLL(root->right);
        //left ke tail ke right mei root daal do
        left.tail->right=root;
        //root ke right mei right ka head
        root->right=right.head;
        l.head=left.head;
        l.tail=right.tail;
        return l;
    }
    else if(root->left and !root->right){
        LinkedList left=BSTtoLL(root->left);
        left.tail->right=root;
        l.head=left.head;
        l.tail=root;
        return l;
    }
    else if(!root->left and root->right){
        LinkedList right=BSTtoLL(root->right);
        root->right=right.head;
        l.head=root;
        l.tail=right.tail;
        return l;

    }
    else{
        l.head=l.tail=root;
        return l;
    }
}