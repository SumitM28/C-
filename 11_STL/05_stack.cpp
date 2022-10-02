#include<iostream>
#include<stack>

using namespace std;

int main(){

    stack<string>s;

    s.push("sumit");
    s.push("mahour");

    cout<<"The top element -->"<<s.top()<<endl;

    s.pop();
    
    cout<<"The top element -->"<<s.top()<<endl;

    cout<<"size of stack "<<s.size()<<endl;

    cout<<"Empty of not "<<s.empty()<<endl;
}