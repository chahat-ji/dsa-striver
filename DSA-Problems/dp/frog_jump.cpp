#include <bits/stdc++.h>
using namespace std;

// similar approach as climbing stair


void fun(int n,vector<int> &arr, int i, vector<int> &min,int temp){
    
    if(i==n){
        // cout<<temp<<" ";
        min.push_back(temp);
        return;
    }
    else if(i>n){
        return;
    }
    fun(n,arr,i+1,min,temp + abs(arr[i]-arr[i+1]));
    fun(n,arr,i+2,min,temp + abs(arr[i] - arr[i+2]));
    return;
}

//more efficient code

int fun2(int i, vector<int> &arr, vector<int> &dp){
    if(i==arr.size()-1){
        return 0;
    }
    if(i>=arr.size()) return 1000000; //value greater than any sum possible

    if(dp[i] != -1) return dp[i];

    int jump1 = abs(arr[i] - arr[i+1]) + fun2(i+1, arr, dp);
    int jump2 = abs(arr[i] - arr[i+2]) + fun2(i+2, arr, dp);

    int minEnergy = min(jump1, jump2);
    dp[i] = minEnergy;  // Store the result in the memoization table

    return minEnergy;

}



int main(){
    int n=5;
    vector<int> arr;
    arr.push_back(30);
    arr.push_back(10);
    arr.push_back(60);
    arr.push_back(10);
    arr.push_back(60);
    arr.push_back(50);

    vector<int> dp;
    fun(n,arr,0,dp,0);

    int min = *min_element(dp.begin(),dp.end());
    cout<<min<<endl;


    vector<int> dp2(arr.size(), -1);
    cout<<fun2(0,arr,dp2);

    return 0;
}