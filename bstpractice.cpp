#include<iostream>
using namespace std;
class node{
    public:
    node* left;
    node* right;
    int data;
    node(int d){
        data =d;
        right=left=NULL;
    }
};
void preorder(node* root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root){
    if(!root){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
void inorder(node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void printrange(node* root,int k1,int k2){
    if(!root){
        return;

    }
    printrange(root->left,k1,k2);
    if(root->data>=k1 and root->data<=k2){
        cout<<root->data<<" ->";
    }
    printrange(root->right,k1,k2);

}
bool isbalanced(node* root){
    if(!root){
        return true;
    }
    int h1=isbalanced(root->left);
    int h2=isbalanced(root->right);
    if(abs(h1-h2)<=1 and isbalanced(root->left) and isbalanced(root->right)){
        return true;

    }
    return false;

}
node* buildbalanced(int ar[],int s,int e){
    if(s>e){
        return NULL;
    }
    //recur
    int m=(s+e)/2;
    node* root=new node(ar[m]);
    root->left=buildbalanced(ar,s,m-1);
    root->right=buildbalanced(ar,m+1,e);


}

class Pair{
    public:
    int height;
    bool isBalanced;

};

Pair checkbalanced(node* root){
    if(!root){
        Pair p;
        p.height=0;
        p.isBalanced=true;
    }

    Pair left=checkbalanced(root->left);
    Pair right=checkbalanced(root->right);

    Pair p;
    p.height=max(left.height,right.height)+1;

    if(abs(left.height-right.height)<=1 and left.isBalanced and right.isBalanced){
        p.isBalanced=true;
    }
    else{
        p.isBalanced=false;
    }
    return p;




}

class Linkedlist{
    public:
    node*head,*tail;
    Linkedlist(){
        head=tail=NULL;
    }
};
Linkedlist bsttoll(node* root){
    Linkedlist l;
    if(!root){
        return l;

    }
    if(root->left and root->right){
        Linkedlist left=bsttoll(root->left);
        Linkedlist right=bsttoll(root->right);
        left.tail->right=root;
        root->right=right.head;
        l.head=left.head;
        l.tail=right.tail;
        return l;
    }
    else if(root->left and !root->right){
        Linkedlist left=bsttoll(root->left);
        left.tail->right=root;
        l.head=left.head;
        l.tail=root;
        return l;
    }
    else if(!root->left and root->right){
        Linkedlist right=bsttoll(root->right);
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
node* insertinbst(node* root,int val){
    if(!root){
        root=new node(val);
        return root;
        
    }
    if(root->data>val){
        root->left=insertinbst(root->left,val);
    }
    else {
        root->right=insertinbst(root->right,val);
    }
    return root;



}
node* createBst(){
    node* root=NULL;
    int data;
    cin>>data;
    while(data !=-1){
        insertinbst(root,data);
        cin>>data;                         
    }
    return root;
}
