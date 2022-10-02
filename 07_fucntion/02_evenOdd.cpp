// create a function that can check the given numevr is even or odd

#include<iostream>
using namespace std;

//  fuction to check the number.
bool isEven(int a){

    if(a%2==0){
        return true;
    }
    return false;
}


int main(){

    int num;
    cout<<"Enter the value of num:";

    cin>>num;

    int ans=isEven(num);
    if(ans==0){
        cout<<"Number is odd.";
    }else{
        cout<<"Number is even";
    }
}