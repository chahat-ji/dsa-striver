#include <bits/stdc++.h>
using namespace std;

void subseq_sum(int i, int arr[], vector<int> &temp, int n,int sum, int cur_sum=0){
    
    if(n==i){
        for(auto it:temp) cur_sum += it;
        if(sum == cur_sum) {
            for(auto it:temp) cout<<it<<" ";
            cout<<endl;
        }
    }

    else{
        temp.push_back(arr[i]);
        // cur_sum += arr[i];

        subseq_sum(i+1, arr,temp,n,sum);

        temp.pop_back();
        // cur_sum -= arr[i];

        subseq_sum(i+1,arr,temp,n,sum);
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    vector<int> temp;
    subseq_sum(0,arr,temp,5,4);
}