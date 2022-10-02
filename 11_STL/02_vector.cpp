// vector is a dynamic array which double its size when it completely filled and what to add more element.

#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int>v;

    // capacity 
    cout<<"the capacity of the vector "<<v.capacity()<<endl;

    for(int i=1;i<10;i++){
        v.push_back(i);
    }
    cout<<"the capacity of the vector "<<v.capacity()<<endl;

     for(int i=0;i<9;i++){
        cout<<v[i]<<" ";
        
    }
    cout<<endl;
    cout<<"At the positon 2 the element is "<<v.at(2)<<endl;

    cout<<"The last element is "<<v.back()<<endl;
    cout<<"The first element is "<<v.front()<<endl;


    cout<<"The size of the vector before clear "<<v.size()<<endl;
    v.clear();
    cout<<"The size of the vector before clear"<<v.size()<<endl;

    // during the clear opetion capacity will remain same.

    vector<int>a(5,1);
    for(int i:a){

        cout<<i<<" ";
    }
    cout<<endl;
    // copy vector
    vector<int> copy(a);
    for(int i:copy){

        cout<<i<<" ";
    }
}