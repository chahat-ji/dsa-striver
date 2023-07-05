#include <bits/stdc++.h>
using namespace std;

// how many different ways to reach 0-n taking 1 or 2 steps at a time?

// approach - 
// i am at 0,
// either i take 1 or 2 steps 
// if i reach n, ans++
// if i exceed n, ans = ans;
// if i less than n, either take 1 or 2 steps again. 

int fun(int n,int i, int &max){
    
    if(i==n){
        max += 1;
        return max;
    }
    else if(i>n){
        return max;
    }
    max = fun(n,i+1,max);
    max =  fun(n,i+2,max);
    return max;
}

int main(){
    int n=5;
    int ans = 0;
    int i=0;
    cout<<fun(n,i,ans);
    return 0;
}