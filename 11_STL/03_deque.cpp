// deque is a dynamic array in which data is stored in the stactic arrays.

#include<iostream>
#include<deque>

using namespace std;


int main(){

    deque<int>d;

    d.push_back(5);
    d.push_front(1);

    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    // d.pop_front();
    // d.pop_back();
//    for(int i:d){
//         cout<<i<<" ";
//     }

    cout<<"print first index elemet"<<d.at(1)<<endl;

    cout<<"front "<<d.front()<<endl;
    cout<<"back "<<d.back()<<endl;

    cout<<d.empty();

    cout<<"before eraes "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"after eraes "<<d.size()<<endl;
}