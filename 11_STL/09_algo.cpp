// now we will discuss about algo in stl

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(){

    vector<int>v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"finding 6 -> "<<binary_search(v.begin(),v.end(),6)<<endl;
    cout<<"lower bound ->"<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;

    int a=5;
    int b=45;

    cout<<"max ->"<<max(a,b);
    cout<<"min ->"<<min(a,b);
    cout<<endl;
    string s="abcd";
    reverse(s.begin(),s.end());
    cout<<"reverse string is "<<s;
}