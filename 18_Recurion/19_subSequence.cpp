// find all the possible sub sequence
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void subSequence(string s,int i,string output,vector<string>& ans){
    if(i>=s.size()){

        ans.push_back(output);
        return;
    }

    // exclude
    subSequence(s,i+1,output,ans);
    
    // include
    char element=s[i];
    output.push_back(element);
    subSequence(s,i+1,output,ans);

}


vector<string> solve(string s){
    vector<string> ans;
    string output="";
    int i=0;
    subSequence(s,i,output,ans);
    return ans;
}



int main(){

    string s;
    cout<<"Enter thr String:";
    cin>>s;

    vector<string> ans=solve(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        cout<<endl;
    }
}