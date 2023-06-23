#include <iostream>
using namespace std;

bool check(string str, int n, int i=0){
    if(i>n/2){
        return true;
    }

    if(str[i] != str[n-i-1]){
        return false;
    }
    
    return check(str,n,i+1);
}

int main(){

    string str;
    cin>>str;

    cout<<check(str,str.size());
}