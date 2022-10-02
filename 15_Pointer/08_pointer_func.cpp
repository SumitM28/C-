//Passing by reference without pointers

#include<iostream>
using namespace std;

void update(int &num){
    num=20;
}
int main(){

    int num=10;

    cout<<"Before updating :";
    cout<<num<<endl;
    cout<<"After updating :";
    update(num);
    cout<<num<<endl;
}