#include <bits/stdc++.h>
using namespace std;

int max_point(vector<vector<int>> &arr, int i, int j, int n,unordered_map<int,int> &mimo){
    if(i>=n) return 0;

    if(mimo[i*10 + j] != 0 ) return mimo[i*10 + j];

    int m1 = arr[i][j] + max_point(arr,i+1,(j+1)%3,n,mimo);
    int m2 = arr[i][j] + max_point(arr,i+1,(j+2)%3,n,mimo);

    mimo[i*10 + j] = max(m1,m2);

    return mimo[i*10 + j];
} 

int main(){

    vector<vector<int>> arr;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<3;j++){
            int temp1;
            cin>>temp1;
            temp.push_back(temp1);
        }
        arr.push_back(temp);
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    unordered_map<int,int> mimo;

    int maxi = -1;
    for(int j=0;j<3;j++){
        maxi = max(maxi, max_point(arr,0,j,n,mimo));
    }
    cout<<endl<<maxi;


    return 0;
}