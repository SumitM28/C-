/* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void letterCombinations(string s,int i,string mapping[],string output,vector< string > &ans){
    if(i>=s.size())
    {   
        ans.push_back(output);
        return;
    }
    int number=s[i]-'0';
    string digitSeq=mapping[number]; 
    for(int j=0;j<digitSeq.size();j++){
        output.push_back(digitSeq[j]);
        letterCombinations(s,i+1,mapping,output,ans);
        output.pop_back();
    }
}

vector< string > solve(string s){
    vector<string> ans;
    if(s==""){
   
        return ans;
    }
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    string output="";
    

    int i=0;
    letterCombinations(s,i,mapping,output,ans);
    return ans;
}



int main(){
    
    string s;
    cout<<"Enter the number:";
    cin>>s;
    vector<string> ans=solve(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}