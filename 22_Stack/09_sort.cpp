// sort a stack using recursion
#include<bits/stdc++.h>
using namespace std;

void insertInStack(stack<int>&s,int data){
    if(s.empty() || (!s.empty() && s.top()<data)){
        s.push(data);
        return;
    }
    int n=s.top();
    s.pop();
    insertInStack(s,data);
    s.push(n);
}

void sort(stack<int>&s){
    if(s.empty()){
        return ;
    }

    int num=s.top();
    s.pop();
    sort(s);
    insertInStack(s,num);
}


void printData(stack<int>s){
    if(s.empty()){
        return ;
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

    // reverse(s);
    // printData(s);
    sort(s);
    printData(s);
}