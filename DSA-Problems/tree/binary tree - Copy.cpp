#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int data;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(node *r){
    if(r == NULL) return;

    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

int main(){

    node *root = new node(0);
    root->left = new node(1);
    root->right = new node(2);

    inorder(root);

    return 0;
}