// check the number is positive or not.
#include <iostream>
using namespace std;

int main()
{

    // int a;
    // cout<<"Enter the number: ";
    // cin>>a;

    // if(a>0){
    //     cout<<"The number "<<a<<" is positive";
    // }else{
    //     cout<<"The number"<<a<<" is negative";

    // }

    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;

    cout << "Enter the value of b: ";
    cin >> b;

    if (a > b)
    {
        cout << "a is greater." << endl;
    }
    else if (b > a)
    {
        cout << "b is greater." << endl;
    }
    else
    {
        cout << "Both are equal" << endl;
    }
}