#include<iostream>
using namespace std;

int main(){

    // we can take input by using cin
    // we can print output in cout
    int a,b;
    cout<<"Enter the value of a:";
    cin>>a;
    cout<<"Enter the value of b:";
    cin>>b;
    cout<<"the value of a "<<a<<" And b "<<b<<endl;

    // out cin does not support the "_"  ,  " \t" ," \n"
    // so we can use cin.get

    int c;
    c=cin.get();
    cout<<"the value of c: "<<c<<endl;

}