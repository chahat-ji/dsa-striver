#include <bits/stdc++.h>
using namespace std;

// similar approach as climbing stair

void fun(int n,int arr[], int i, vector<int> &min,int temp){
    
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

int main(){
    int n=5;
    int arr[6] = {30,10,60,10,60,50};
    vector<int> dp;
    fun(n,arr,0,dp,0);

    int min = *min_element(dp.begin(),dp.end());
    cout<<min;

    return 0;
}