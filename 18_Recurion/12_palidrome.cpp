// check the given string is palidrome or not.
#include<iostream>
#include<string>
using namespace std;

bool checkPalidrom(string &s,int i,int j){
  

    if(i>j){
        return true;

    }
    if(s[i]!=s[j]) return false;
    
    return checkPalidrom(s,i+1,j-1);
    
    
}

int main(){

    string s;
    cout<<"Enter a string:";
    cin>>s;
    int n=s.size();
    cout<<checkPalidrom(s, 0,n-1);
    

    
}