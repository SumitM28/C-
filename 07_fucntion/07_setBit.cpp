// find the total set bit in the 2 number.

#include<iostream>
using namespace std;


int main(){

    int a,b;
    cout<<"Enter the value of a:";
    cin>>a;
    cout<<"Enter the value of b:";
    cin>>b;

    int ans=0;

    while (a!=0)
    {
        if(a&1==1){
            ans++;
        }
        a=a>>1;
    }
    while (b!=0)
    {
        if(b&1==1){
            ans++;
        }
        b=b>>1;
    }
    
    cout<<ans<<endl;
}