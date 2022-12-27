#include<iostream>
#include<queue>
#include<stack>
using namespace std;


// using only stack.
void interLeave(queue<int>&q,int n){
    stack<int>s;
    for(int i=0;i<n/2;i++){
        s.push(q.front());
        q.pop();
    }

    while (s.size()>0)
    {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < n/2; i++)
    {
        int temp=q.front();
        q.pop();
        q.push(temp);
    }
    
    for(int i=0;i<n/2;i++){
        s.push(q.front());
        q.pop();
    }
    while (s.size()>0)
    {
        int temp=q.front();
        q.pop();
        q.push(s.top());
        q.push(temp);
        s.pop();
    }
    
    
}

int main(){

    queue<int>q;
    cout<<"Enter the length: ";
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        q.push(temp);
    }
    
    interLeave(q,n);
    while (q.size()>0)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    


}