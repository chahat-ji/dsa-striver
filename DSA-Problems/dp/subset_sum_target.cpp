#include <bits/stdc++.h>
using namespace std;

void fun(int arr[], int n, int target, bool &ans, int sum=0){
    if(n<0){
        if(sum==target){
            ans = true;
        }
        return;
    }
    //take it
    fun(arr,n-1,target,ans,sum+arr[n]);

    //not take it
    fun(arr,n-1,target,ans,sum);
    
}

bool fun2(int arr[], int n, int target){
    if(target == 0){
        return true;
    }    
    if(n==0) return target == arr[0];

    //take
    bool take = fun2(arr,n-1,target-arr[n]);

    //not take
    bool not_take = fun2(arr,n-1,target);

    return take || not_take;
}

int main(){
    int arr[5] = {10,5,3,4,5};
    int n=5;
    int target = 16;
    
    bool ans = false;
    
    ans = fun2(arr,n-1,target);
    
    // fun(arr,n-1,target,ans);

    if(ans) cout<<"yes";
    else cout<<"no";
}