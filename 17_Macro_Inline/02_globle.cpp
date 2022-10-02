// globle variable in cpp
#include<iostream>
using namespace std;

// globle variable
int num=5;

void fun1(){
    cout<<num<<endl;
}
void fun2(){
    cout<<num<<endl;
}

int main(){

    cout<<num<<endl;
    fun1();
    fun2();

}