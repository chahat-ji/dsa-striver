#include <iostream>
using namespace std;

void print(string name, int n, int i=1){
    if(i>n) return;

    cout<<name<<endl;

    print(name,n,i+1);
}

int main(){
    string name;
    int n;
    cin>>name;
    cin>>n;

    print(name,n);
}