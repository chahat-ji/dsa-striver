#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr, int i, vector<int> &memo){
    if(i==0 && arr.size()%2==0) return arr[i];
    else if(i<=0) return 0;

    if(memo[i] != -1) return memo[i];

    int pick = arr[i] + fun(arr, i-2, memo);
    int notpick = 0 + fun(arr,i-1,memo);

    memo[i] = max(pick,notpick);
    return memo[i];
}


// int fun2(vector<int> &arr, int i, vector<int> &memo){
//     // if(i==0) return arr[i];
//     if(i<=0) return INT_MAX;

//     if(memo[i] != -1) return memo[i];

//     int pick = arr[i] + fun(arr, i-2, memo);
//     int notpick = 0 + fun(arr,i-1,memo);

//     return memo[i] = max(pick,notpick);
// }

int robber(vector<int> &arr, int i){
    vector<int> memo(arr.size(),-1);
    return fun(arr,i,memo);

}

int main(){

    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    vector<int> memo(arr.size(),-1);
    cout<<fun(arr,n-1,memo);
    return 0;
}