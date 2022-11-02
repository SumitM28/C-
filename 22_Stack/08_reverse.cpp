// reverse a stack using recursion
#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&s,int data){
    if(s.empty()){
        s.push(data);
        return;
    }
    int temp=s.top();
    s.pop();
    insertAtBottom(s,data);
    s.push(temp);
}

void reverse(stack<int>&s){
    if(s.empty()){
        return;
    }

    int temp=s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,temp);
}




void printData(stack<int>&s){
    if(s.empty()){
        return;
    }
    int data=s.top();
    s.pop();
    printData(s);
    cout<<data<<" ";
}

int main(){

    stack<int>s;
 
    int size;
    cout<<"Enter the size of stack:";
    cin>>size;
    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        s.push(temp);
    }

    reverse(s);

    printData(s);
}