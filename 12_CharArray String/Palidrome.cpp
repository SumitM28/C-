// check polidrome if given string is palidrome of not.
#include<iostream>
using namespace std;


// check palidrome
bool checkPalidrome(string str,int n){
    int i=0,j=n-1;
    while (i<=j)
    {
        if(tolower(str[i])!=tolower(str[j])){
            return false;
        }
        i++,j--;
    }
    return true;
}
int main(){
    string s;
    cout<<"Enter the String ";
    cin>>s;

    bool ans=checkPalidrome(s,s.size());

    if(ans==1){
        cout<<"String is palidrome.";
    }
    else{
        cout<<"String is not palidrome.";
    }
}
