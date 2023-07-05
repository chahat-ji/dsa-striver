#include <bits/stdc++.h>
using namespace std;

class node {
    public:

    int data;
    node* l;
    node* r;

    node(int val){
        data = val;
        l = NULL;
        r = NULL;
    }
};

void inorder(node* root){
    if(root){
        inorder(root->l);
        cout<<root->data<<" ";
        inorder(root->r);
    }
}

void preorder(node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->l);
        preorder(root->r);
    }
}

void postorder(node* root){
    if(root){
        postorder(root->l);
        postorder(root->r);
        cout<<root->data<<" ";
    }
}


int main(){
    node* root = new node(0);
    root->l = new node(1);
    root->r = new node(2);
    root->l->l = new node(3);
    root->l->r = new node(4);
    root->r->l = new node(5);

    preorder(root); cout<<endl;
    inorder(root); cout<<endl;
    postorder(root); cout<<endl;

   return 0;
}