// find longest common prefix.
#include <iostream>
#include<vector>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int countChild=0;
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        countChild=0;
        isTerminal=false;
    }
};

class Trie{
    public:
    TrieNode* root;
    
    Trie(char ch){
        root= new TrieNode(ch);
    }
    void insertUtils(TrieNode* root, string word){
        if(word.length()==0){
            return ;
        }
        int idx=word[0]-'a';
        TrieNode* child;
        if(root->children[idx] != NULL){
            child=root->children[idx];
        }else
        {
            child= new TrieNode(word[0]);
            root->countChild++;
            root->children[idx]=child;
        }
        insertUtils(child,word.substr(1));
    }
    
    void insertWord(string word){
        insertUtils(root,word);
    }
      
    void lcp(string str, string& ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            
            if(root->countChild==1){
                ans.push_back(ch);
                int idx=ch-'a';
                root=root->children[idx];
            }else{
                break;
            }
            
            if(root->isTerminal){
                break;
            }
        }
    }
};
string longestCommonPrefixOptimise(vector<string> &arr, int n)
{
    Trie* t= new Trie('/');
    
    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }
    string first=arr[0];
    string ans="";
    t->lcp(first,ans);
    return ans;
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];

        bool match = true;
        for (int j = 1; j < n; j++)
        {
            if (ch != arr[j][i] || arr[j].size() < i)
            {
                match = false;
                break;
            }
        }
        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

int main()
{

    vector<string> arr;
    arr.push_back("coding");
    arr.push_back("codezen");
    arr.push_back("codingninja");
    arr.push_back("coder");

    cout<<longestCommonPrefixOptimise(arr,arr.size());

}
