#include<iostream>
using namespace std;

// time complexity O(logn)
int main(){

    int a,b;
    cout<<"Enter the value:";
    cin>>a;
    cout<<"Enter the power:";
    cin>>b;

    int res=1;
    while (b>0)
    {
        if(b&1){// odd
            res=res*a;
        }
        a=a*a;
        b=b>>1;
    }
    cout<<res;
}