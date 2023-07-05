#include <bits/stdc++.h>
using namespace std;

class node {
    public:

    int data;
    node *l, *r;

    node(int val){
        data = val;
        l = NULL;
        r = NULL;
    }
};


vector<vector<int>> level_order(node* root){
    vector<vector<int>> ans;
    if(!root) return ans;

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            node* temp = q.front();
            q.pop();

            if(temp->l) q.push(temp->l);
            if(temp->r) q.push(temp->r);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}

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

    vector<vector<int>> level;
    level = level_order(root);
    
    for(int i=0;i<level.size();i++){
        for(int j=0;j<level[i].size();j++){
            cout<<level[i][j]<<" ";
        }
        cout<<endl;
    }

   return 0;
}