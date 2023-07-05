#include <bits/stdc++.h>
using namespace std;
int n=4,m=5;

int fun(int arr[][5],int i, int j, unordered_map<string,int> &mimo){
    if(j<0 && j>m-1) return -1e8;
    if(i==0) return arr[i][j];
        

    string key = to_string(i) + "," + to_string(j);
    if(mimo[key] != 0) return mimo[key];

    int left = arr[i][j] + fun(arr,i-1,j-1,mimo);
    int up = arr[i][j] + fun(arr,i-1,j,mimo);
    int right = arr[i][j] + fun(arr,i-1,j+1, mimo);

    return mimo[key] = max(left,max(up,right));
}

int fall(int arr[][5]){
    
    unordered_map<string,int> mimo;
    int ans = 0;
    for(int k=0;k<m;k++){
        ans = max(ans,fun(arr,n-1,k,mimo));
        // cout<<ans<<" "; 
    }

    return ans;
}

int main(){
    int arr[n][5] = {
        {1,2,3,4,5},
        {7,6,2,8,4},
        {4,1,9,3,6},
        {9,1,1,4,7}
    };

    //tabular method
    int dp[n][m];
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0) dp[i][j] = arr[i][j];
            else{
                int left=0,up=0,right=0; //assinging with 0 means no previous value
                if(i>0 && j>0) left = arr[i][j] + dp[i-1][j-1];
                if(i>0) up = arr[i][j] + dp[i-1][j];
                if(i>0 && j<m-1) right = arr[i][j] + dp[i-1][j+1];

                dp[i][j] = max(left,max(up,right)); 
                if(i==n-1) ans = max(ans,dp[i][j]);
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<ans<<endl;


    //memoization method
    cout<<fall(arr);
    return 0;
}


// 9 1 1 4 7 
// 13 10 13 10 13
// 20 19 15 21 17
// 21 22 24 25 26