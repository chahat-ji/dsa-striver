#include <iostream>
using namespace std;

void reverse(int arr[], int l, int r){
    if(l>=r) return;

    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;

    reverse(arr,l+1,r-1);
}

int main(){

    int arr[5] = {1,2,3,4,5};

    reverse(arr,0,4);

    for(int i=0;i<5;i++) cout<<arr[i]<<" ";
}