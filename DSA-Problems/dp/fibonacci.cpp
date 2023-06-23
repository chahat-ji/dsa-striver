#include <bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int>&dp){
    if(n<=1){
        dp[n] = n;
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    } 
    else{
        dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
        return dp[n];
    } 
}

int main(){
    int n=5;
    vector<int> dp(n,-1);
    cout<<fibo(n,dp);
}