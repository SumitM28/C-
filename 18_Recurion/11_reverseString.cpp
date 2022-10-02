// reverse the given sting
#include<iostream>
#include<string>
using namespace std;

void reverse(string &s,int i,int j){
  

    if(i>j) return ;

    swap(s[i],s[j]);

    reverse(s,i+1,j-1);
    
    
}

int main(){

    string s;
    cout<<"Enter a string:";
    cin>>s;
    int n=s.size();
   reverse(s, 0,n-1);
    cout<<s;

    
}