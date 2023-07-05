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



//      0
//    /   \
//   1     2
//  / \   /
// 3   4 5


int main(){
    node* root = new node(0);
    root->l = new node(1);
    root->r = new node(2);
    root->l->l = new node(3);
    root->l->r = new node(4);
    root->r->l = new node(5);

    //preorder traversal

    stack<node*> st;
    st.push(root);

    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->r) st.push(temp->r);
        if(temp->l) st.push(temp->l);
    }

   return 0;
}