#include <bits/stdc++.h>
using namespace std;

int paths(int arr[][3], int i, int j,unordered_map<string,int> &mimo){
    if(i<0 || j<0) return 100000; //maximum possible sum value
    if(i==0 && j==0)return arr[i][j];

    string key = to_string(i) + "," + to_string(j);
    if(mimo[key] != 0) return mimo[key];


    int up = arr[i][j] + paths(arr,i-1,j,mimo);
    int left = arr[i][j] + paths(arr,i,j-1,mimo);

    return mimo[key] = min(up , left);
}

int main(){
    int arr[2][3] = {
        {5,9,6},
        {11,5,2}
    };

    //tabulation
    int dp[2][3];

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            if(i==0 && j==0) dp[i][j] = arr[i][j];
            else{
                int up = 1e9,left = 1e9; //1e9 because either they have right value or very value(which we will not consider)
                if(i>0) up = arr[i][j] + dp[i-1][j];
                if(j>0) left = arr[i][j] + dp[i][j-1];

                dp[i][j] = min(up,left);
            }
        }
    }

    cout<<dp[1][2]<<endl;




    //memoization
    unordered_map<string,int> mimo;
    cout<<paths(arr,1,2,mimo);

    
    return 0;
}