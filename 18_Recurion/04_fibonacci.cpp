// find the nth fibbonacci number.
#include<iostream>
using namespace std;

// fibonacci fucntion
int fib(int num){
    if(num==0) return 0;
    if(num==1) return 1;

    return fib(num-1)+fib(num-2);
}

int main(){

    int num;
    cout<<"Enter the nth term:";
    cin>>num;
    cout<<fib(num);
}