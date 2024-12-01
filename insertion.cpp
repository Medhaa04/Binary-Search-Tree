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
node* insertInBST(node* root, int data) {
	if (!root) {
		root = new node(data);
		return root;
	}
	if (root->data > data) {
		root->left = insertInBST(root->left, data);
	}
	else {
		root->right = insertInBST(root->right, data);
	}

	return root;
}

node* createBst(){
    node* root=NULL;
    int data;
    cin>>data;
    while(data !=-1){
        insertInBST(root,data);
        cin>>data;                         
    }
    return root;
}