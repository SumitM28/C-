// program to check the given is valid palindrome or not.
#include<iostream>
using namespace std;

// check valid character or not
bool valid(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
        return true;
    }
    return false;
}

// check palidrome function.
bool palindrome(string s){
    int i=0;
    int j=s.length()-1;

    while (i<=j)
    {
        if(s[i]!=s[j]){
            return false;
        }
        i++,j--;
    }
    return true;
    
}

int main(){
    string s="A man, a plan, a canal: Panama";
    
    string temp;
    for (int i = 0; i < s.length(); i++)
    {
        if (valid(s[i]))
        {
            temp.push_back(s[i]);
        }
        
    }
    for (int i = 0; i < temp.length(); i++)
    {
       temp[i]=tolower(temp[i]);
    }
    
    if(palindrome(temp)){
        cout<<"palindrome.";
    }
    else{
        cout<<"Not palindrome.";
    }
}