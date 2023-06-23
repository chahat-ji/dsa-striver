#include <bits/stdc++.h>
using namespace std;


int max_sum(vector<int> &arr, int n){
    if(n==0) return arr[n];
    if(n<0) return 0;

    // inlcude nth index
    int yes = arr[n] + max_sum(arr,n-2);
    int no = 0 + max_sum(arr,n-1);

    return max(yes,no);
}

//more efficient memoization technique
int fun2(vector<int> &arr, int n, vector<int> &memo){
    if(n==0) return arr[n];
    if(n<0) return 0;

    if(memo[n] != -1) return memo[n];

    int yes = arr[n] + fun2(arr,n-2,memo);
    int no = 0 + fun2(arr,n-1,memo);

    memo[n] = max(yes,no);

    return memo[n];

}

int main(){

    // 5 1 2 15 4
    vector<int> arr;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<max_sum(arr,n-1)<<endl;

    //memoization efficient way
    vector<int> memo(arr.size(),-1);
    cout<<fun2(arr,n-1,memo);
}