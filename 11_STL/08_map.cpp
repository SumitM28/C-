// program to hasmap in cpp.
#include<iostream>
#include<map>
using namespace std;

int main(){


    map<int, string>m;


    m[1]="sumit";
    m[12]="mahour";
    m[2]="love";

    m.insert({5,"chetan"});
    for(auto i:m){
        cout<<i.first<<" ";
    }
    cout<<endl;
    cout<<"before erase"<<endl;
    for(auto i:m){
        cout<<i.first<<":"<<i.second<<endl;
    }
    cout<<endl;

    cout<<"find 5-->"<<m.count(5)<<endl;

    

    m.erase(5);
    cout<<"After erase"<<endl;
      for(auto i:m){
        cout<<i.first<<":"<<i.second<<endl;
    }
    cout<<endl;
}