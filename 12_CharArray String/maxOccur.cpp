// find the max occuring character in the sting.

#include<iostream>
#include<map>
using namespace std;


// by using create a array .
char maxOcc(string s){
   int arr[26]={0};

   for (int i = 0; i <s.length(); i++)
   {
        int number=0;
        char ch=s[i];
        if(ch>='a' && ch<='z'){
            number=ch-'a';
        }else{
            number=ch-'A';
        }
        arr[number]++;
   }

    int maxi=-1;
    int ans=0;
    for (int i = 0; i < 26; i++)
    {
        if(maxi<arr[i]){
            ans=i;
            maxi=arr[i];
        }
    }
    char finalAns='a'+ans;
    return finalAns;
    
}


// by usign hasmap
char getMaxOccuringChar(string str){
    map<char,int>m;
    for (int i = 0; i < str.length(); i++)
    {
        m[str[i]]++;
    }

    int max=0;
    char ans;
    for(auto i:m){
        if(max<i.second){
            max=i.second;
            ans=i.first;
        }
    }
    return ans;
    
}

int main(){

    string s;
    cout<<"Enter the string: ";
    cin>>s;

    char ch=getMaxOccuringChar(s);
    cout<<ch;
    
}