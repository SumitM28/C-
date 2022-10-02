// find the nth term in the given ap= 3*n+2
#include<iostream>
using namespace std;

int ap(int n){

    return ((3*n)+7);
}

int main(){


    int n;
    cout<<"Enter the number:";
    cin>>n;

    cout<<ap(n)<<endl;

}