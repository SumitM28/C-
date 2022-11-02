// reverse a strign using stack
#include<iostream>
#include<stack>
using namespace std;


string reverse(string name){

    stack<char>s;
    for (int i = 0; i < name.size(); i++)
    {
        s.push(name[i]);
    }
    
    for (int i = 0; i < name.size(); i++)
    {
        
        name[i]=s.top();
        s.pop();
    }
    return name;
    
}

int main(){


    string name;
    cout<<"Enter your name:";
    cin>>name;

    string reverseName=reverse(name);
    cout<<reverseName;

}