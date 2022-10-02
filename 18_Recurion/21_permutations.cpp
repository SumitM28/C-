// find the all the possible permutation of a string
#include<iostream>
#include<vector>
using namespace std;

void permutaions(string s,int i,vector<string> &ans){
    if(i>=s.size()){
        ans.push_back(s);
        return;
    }

    for (int j = i; j < s.size(); j++)
    {
        swap(s[i],s[j]);
        permutaions(s,i+1,ans);
        swap(s[i],s[j]);
    }
    
}


int main(){

    string s;
    cout<<"Enter the string:";
    cin>>s;

    vector<string>ans;
    permutaions(s,0,ans);
    for(auto i:ans){
        cout<<i<<" ";
    }
}