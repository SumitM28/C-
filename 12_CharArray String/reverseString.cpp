// reverse word in the string;

#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s="sumit mahour";
    vector<string>tmp;
    string word="";
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]!=' '){
            word.push_back(s[i]);
        }
        else{
            tmp.push_back(word);
            word="";
        }
    }
    tmp.push_back(word);
    word="";
    

  
    int i=0,j=tmp.size()-1;
    while (i<=j)
    {
        swap(tmp[i],tmp[j]);
        i++,j--;
    }
    
    for(auto i:tmp){
        cout<<i<<" ";
    }
}