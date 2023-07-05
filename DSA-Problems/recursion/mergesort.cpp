#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int high){
    int mid = low + high;
    mid = mid/2;

    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }

    while(left<= mid){
        temp.push_back(arr[left++]);
    }
    while(right<=high){
        temp.push_back(arr[right++]);
    }

    for(auto it:temp){
        arr[low++] = it;
    }
}

void mergesort(int arr[], int low, int high){
    if(low>=high) return;
    int mid = (low+high)/2;

    mergesort(arr,low,mid);
    mergesort(arr, mid+1, high);
    merge(arr,low,high);
}


int main(){

    int arr[5] = {2,5,1,6,3};

    mergesort(arr,0,4);

    for(int i=0;i<5;i++) cout<<arr[i]<<" ";
}
    

