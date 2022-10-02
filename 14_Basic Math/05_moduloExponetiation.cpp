// find the modulo Exponentiation.
#include<iostream>
using namespace std;

// time complexity O(logn)
int main(){

    int a,b,m;
    cout<<"Enter the value:";
    cin>>a;
    cout<<"Enter the power:";
    cin>>b;
    cout<<"Enter the value of modulo:";
    cin>>m;

    int res=1;
    while (b>0)
    {
        if(b&1){// odd
            res= ( 1LL* (res) * (a)%m)%m;
        }
        a=(1LL*(a)%m * (a)%m)%m;
        b=b>>1;
    }
    cout<<res;
}