// find the power of a number by using recursion.
#include<iostream>
using namespace std;


int getPower(int n,int p){
    if(p==0){
        return 1;
    }
    if(p==1){
        return n;
    }
    int ans=getPower(n,p/2);
    // if p is odd
    if(p&1){
        return n*ans*ans;
    }else{
        // when p is even
        return ans*ans;
    }

    
}

int main(){

    int n,p;
    cout<<"Enter the number:";
    cin>>n;
    cout<<"Enter the power:";
    cin>>p;

    cout<<getPower(n,p);
}