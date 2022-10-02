#include <iostream>
#include <queue>

using namespace std;

int main()
{

    // max headp
    priority_queue<int> maxi;

    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(0);
    maxi.push(10);
    maxi.push(5);
    maxi.push(2);

    cout<<"Size the maxi "<<maxi.size()<<endl;
    int n=maxi.size();
    for(int i=0;i<n;i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;
    mini.push(1);
    mini.push(0);
    mini.push(10);
    mini.push(5);
    mini.push(2);
    
    cout<<"Size the maxi "<<mini.size()<<endl;
    n=mini.size();
    for(int i=0;i<n;i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;

    cout<<" Khali ho kya bhai "<<mini.empty();
}