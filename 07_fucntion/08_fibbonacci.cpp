// create a program to find the nth fibbonacci term

#include<iostream>
using namespace std;

int fibb(int n){
    if(n==1){
        return 1;
    }

    return fibb(n-1)+fibb(n-2);
}

int main(){
    
    int n;
    cout<<"Enter the number:";
    cin>>n;

    int ans=fibb(n);
    cout<<ans<<endl;
}