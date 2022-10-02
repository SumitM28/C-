// pointer and address.

#include<iostream>
using namespace std;

int main(){
    
    int var=5;

    // we can get the address of the var by using & operator.
    cout<<&var<<endl;


    // pointer
    int *ptr=&var;
    cout<<"Address is :"<<ptr<<endl;
    cout<<"Address is :"<<*ptr<<endl;
    cout<<"The size of ptr :"<<sizeof(ptr)<<endl;
    // we can change the value by using pointer also.
    *ptr=10;
    cout<<var<<endl;
    cout<<*ptr<<endl;


    // character adderess store.
    char ch='a';
    char *ptrCh=&ch;
    cout<<ptrCh<<endl;

}