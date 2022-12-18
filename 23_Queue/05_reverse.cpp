// reverse the queue.
#include<bits/stdc++.h>
using namespace std;


// algorithm 1
queue<int> reverseQ(queue<int>q){
    stack<int>s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    
    return q;
    
}


// using recursion

void reverseQRecursive(queue<int>&q){
    // base case
    if(q.empty()){
        return;
    }

    int element=q.front();
    q.pop();
    reverseQRecursive(q);
    q.push(element);
    
}


int main(){

    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // queue<int>ans=reverseQ(q);
    reverseQRecursive(q);
    queue<int>ans=q;
    while (!ans.empty())
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }
    

}