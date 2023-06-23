#include <bits/stdc++.h>
using namespace std;

void subseq(int i, int arr[], vector<int> &temp, int n){
    if(n==i){
        for(auto it:temp) cout<<it<<" ";
        cout<<endl;
    }

    else{
        temp.push_back(arr[i]);

        subseq(i+1, arr,temp,n);

        temp.pop_back();

        subseq(i+1,arr,temp,n);
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    vector<int> temp;
    subseq(0,arr,temp,3);
}