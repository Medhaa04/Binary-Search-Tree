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
void levelOrder(node* root) {
	if (!root) {
		return;
	}

	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node* n = q.front();
		q.pop();

		if (n != NULL) {
			cout << n->data << " ";
			if (n->left != NULL) {
				q.push(n->left);
			}
			if (n->right != NULL) {
				q.push(n->right);
			}
		}
		else {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		}
	}
}
