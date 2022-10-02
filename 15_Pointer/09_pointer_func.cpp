// Passing by reference using pointers

#include<iostream>
using namespace std;

void update(int *num){
    // num=num+1;
    // kuch change hoga kya -- bilkul nhi
    *num=20;
}
int main(){

    int num=10;

    cout<<"Before updating :";
    cout<<num<<endl;
    cout<<"After updating :";
    update(&num);
    cout<<num<<endl;
}