// create a fucntion that can find the power of a by b time

#include<iostream>
using namespace std;

int power(int a , int b){
    

    int ans= 1;

    for(int i=1;i<=b;i++){
        ans=ans*a;
    }
    return ans;
}

int main(){

    int a,b;

    cout<<"Enter the value of a:";
    cin>>a;

    cout<<"Entet the value of b:";
    cin>>b;

    int res=power(a,b);

    cout<<"The power of a by b time: "<<res<<endl;
}
