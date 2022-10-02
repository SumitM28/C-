// create a function that can find the nCr.

#include<iostream>
using namespace std;

// program to find factorial.
int factorial(int num){


    if(num==0){
        return 1;

    }

    int fac=1;
    while (num>0)
    {
        fac=fac*num;
        num--;
    }
    return fac;
    
}

// program to find ncr
int nCr(int n, int r){

    // this case is happen when n is less than r.
    if(n<r){
        return 0;
    }


    int num=factorial(n);
    
    int denom=factorial(r)*factorial(n-r);
    

    int ans=num/denom;
    
    return ans;
}


int main(){

    int n,r;
    cout<<"Enter the value of n:";
    cin>>n;

    cout<<"Enter the value of r:";
    cin>>r;
    int ans=nCr(n,r);
    cout<<ans<<endl;
}