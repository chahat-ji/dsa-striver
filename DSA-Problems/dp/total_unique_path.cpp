#include <bits/stdc++.h>
using namespace std;

int paths(int n, int m, unordered_map<string,int> &mimo, int i=0, int j=0){
    if(i>=n) return 0;
    else if(j>=m) return 0;
    else if(i==n-1 && j==m-1) return 1;

    if(mimo[to_string(i)+to_string(j)] != 0) return mimo[to_string(i)+to_string(j)];

    int down = paths(n,m,mimo,i+1,j);
    int right = paths(n,m,mimo,i,j+1);

    return mimo[to_string(i)+to_string(j)] = down + right;
}

int main(){
    unordered_map<string,int> mimo;
    cout<<paths(1,1,mimo);
    return 0;
}