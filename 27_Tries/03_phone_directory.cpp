#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode * children[26];
    TrieNode(char data){
        this->data=data;
        this->isTerminal=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie{
    public:
    TrieNode *root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode *root,string word){
        //base condition
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        TrieNode *child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }
    void insert(string word){
        insertUtil(root,word);
    }
    void printSuggestions(TrieNode *curr,vector<string> &temp,string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++){
            TrieNode *next=curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
        
    }
  vector<vector<string>> getSuggestions(string &str){
      TrieNode *prev=root;
      string prefix="";
      vector<vector<string>>out;
      for(int i=0;i<str.size();i++){
          char lastch=str[i];
          prefix.push_back(lastch);
          int index=lastch-'a';
          if(prev->children[index]==NULL){
              break;
          }
          else{
              vector<string>temp;
              printSuggestions(prev->children[index],temp,prefix);
              out.push_back(temp);
              temp.clear();
              prev=prev->children[index];
              
          }
      }
      return out;
  }  
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //inserting all the given words into trie
    Trie *t=new Trie();
    for(int i=0;i<contactList.size();i++){
        t->insert(contactList[i]);
    }
    return t->getSuggestions(queryStr);
}
int main(){

}
