// insert a element at the bottom of the stack
#include<bits/stdc++.h>
using namespace std;

void printData(stack<int>&s){
    if(s.empty()){
        return;
    }
    int data=s.top();
    s.pop();
    printData(s);
    cout<<data<<" ";
}

void insertAtBottom(stack<int>&s,int data){
    if(s.empty()){
        s.push(data);
        return ;
    }

    int temp=s.top();
    s.pop();
    insertAtBottom(s,data);
    s.push(temp);
}

int main(){

    stack<int>s;
    // cout<<s.size();
    int size;
    cout<<"Enter the size of stack:";
    cin>>size;
    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        s.push(temp);
    }
    // printData(s);

    int data;
    cout<<"Enter data to be push:";
    cin>>data;

    insertAtBottom(s,data);
    printData(s);
}