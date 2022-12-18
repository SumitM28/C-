// reverse the fisrt k elements in the queue.
#include <bits/stdc++.h>
using namespace std;

queue<int> reverseFirstK(queue<int> q,int k){
    stack<int>s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    int t=q.size()-k;
    while (t--)
    {
        int val=q.front();
        q.pop();
        q.push(val);
    }
    

    return q;
    
    
}


int main()
{

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k=3;
    queue<int> ans=reverseFirstK(q,k);

    while (ans.size()>0)
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }
    
}