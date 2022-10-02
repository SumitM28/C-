// find the GCD (greatest common divisor) or HCF (highest common factor)
#include<iostream>
using namespace std;


// by subtracing method
int GCD(int a,int b){
    if (a==0)
    {
        return b;
    }
    if(b==0){
        return a;
    }
    while (a!=b)
    {
        if(a>b){
            a=a-b;
        }else{
            b=b-a;
        }
    }
    return a;
}


// HCF by recursive method and divide method.
int HCF(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return HCF(b,a%b);
    }
}

/* brute force approach.

int ans=0;
for(int i=1;i<=min(a,b);i++){
    if(a%i==0 && b%i==0){
        ans=i;
    }
}
*/


int main(){
    int a,b;
    cout<<"Enter the value of a:";
    cin>>a;
    cout<<"Enter the value of b:";
    cin>>b;

    cout<<"The HCF/GCD of "<<a<<" and "<<b<<" is ";
    // int ans=GCD(a,b);
    // cout<<ans;
    

    int ans1=HCF(a,b);
    cout<<ans1;
}