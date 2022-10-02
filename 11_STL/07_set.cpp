// set in stl.

#include<iostream>
#include<set>
using namespace std;


int main(){

    set<int>s;

    s.insert(10);
    s.insert(1);
    s.insert(11);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(50);
    s.insert(50);
    s.insert(50);

    for(int i:s){
        cout<<i<<" ";
    }cout<<endl;

    set<int>::iterator it=s.begin();
    it++;
    s.erase(it);

    for(auto i:s){
        cout<<i<<" ";
    }cout<<endl;

    // count to check element if present in the set or not.
    cout<<"5 is present or not-->"<<s.count(5)<<endl;

    set<int>::iterator itr=s.find(5);

    for(auto it =itr;it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

}