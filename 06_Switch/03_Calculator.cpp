// create a basic calculator which perform ' + - * /'

#include<iostream>
using namespace std;

int main(){

    char ch;
    cout<<"Enter the operation:";
    cin>>ch;

    int a,b;
    cout<<"Enter the number first:";
    cin>>a;

    cout<<"Enter the number second:";
    cin>>b;

    switch (ch)
    {
    case '+':
        cout<<"The addition of a and b :"<<a+b<<endl;
        break;
    
    case '-':
        cout<<"The addition of a and b :"<<a-b<<endl;
        break;
    
    case '*':
        cout<<"The addition of a and b :"<<a*b<<endl;
        break;
    
    case '/':
        cout<<"The addition of a and b :"<<a/b<<endl;
        break;
    
    default:
    cout<<"Operation does not exist!";
        break;
    }

}