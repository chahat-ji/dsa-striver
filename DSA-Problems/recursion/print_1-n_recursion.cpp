#include <iostream>
using namespace std;

void print(int n, int i=1){
    if(i>n) return;

    cout<<i<<endl;

    print(n,i+1);
}

int main(){
    int n;
    cin>>n;

    print(n);
}