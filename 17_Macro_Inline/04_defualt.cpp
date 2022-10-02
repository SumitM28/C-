// default argument in the cpp
#include<iostream>
using namespace std;


int add(int a,int b, int c=0){
    return a+b+c;
}

int main(){

    int a,b,c;
    cin>>a>>b>>c;

    int ans=add(a,b);
    cout<<ans<<endl;

    ans=add(a,b,c);
    cout<<ans<<endl;
    
}