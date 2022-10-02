// pointer and function 
#include<iostream>
using namespace std;

// fucntion for pass by value
void update(int num){
    num=10;
}

// function for pass by reference
void updateByRef(int &num){
    num=10;
}

int main(){

    int num=5;

    cout<<"Before update by pass by value"<<endl;
    cout<<num<<endl;
    cout<<"After update by pass by value"<<endl;
    update(num);
    cout<<num<<endl;


    cout<<"Before update by pass by reference"<<endl;
    cout<<num<<endl;
    cout<<"After update by pass by reference"<<endl;
    updateByRef(num);
    cout<<num<<endl;




    
}