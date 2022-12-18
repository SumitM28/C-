// first non repeating character in stream
#include<bits/stdc++.h>
using namespace std;


string firstNonRepeating(string s,int n){
    unordered_map<char,int>count;
    queue<char>q;
    string ans;

    for(int i=0;i<n;i++){

        // increase the count
        count[s[i]]++;

        // push in queue
        q.push(s[i]);

        // check top is repeating element or not
        while (!q.empty())
        {
            // repeating character
            if(count[q.front()]>1){
                q.pop();
            }else{
                // non repeating character
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
        

    }
    return ans;
}


int main(){

    string s="aabc";
    string op=firstNonRepeating(s,s.size());
    cout<<op;
}