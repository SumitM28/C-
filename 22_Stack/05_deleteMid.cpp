// delete middle form the stack
#include<iostream>
#include<stack>
using namespace std;

void deleteMid(stack<int>&s,int count,int size){

    // base case
    if(count==size/2){
        s.pop();
        return;
    }

    int temp=s.top();
    s.pop();
    deleteMid(s,count+1,size);
    s.push(temp);    
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
    cout<<"Enter the size:";
    cin>>size;
    cout<<"Enter the input"<<endl;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin>>temp;
        s.push(temp);
    }
    int count=0;
    deleteMid(s,count,size);

//    while (!s.empty())
//    {
//         int data=s.top();
//         cout<<data<<" ";
//         s.pop();
//    }
    printData(s);
      
}
    
