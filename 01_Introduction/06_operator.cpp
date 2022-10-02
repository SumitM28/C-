// program to perform some bitwise operator.

#include <iostream>
using namespace std;

int main()
{

    int x, y;
    cout << "Enter the Input:";
    cin >> x;
    cout << "Enter the Input:";
    cin >> y;

    // the and & operation
    float res = x & y;
    cout << res << endl;

    // the OR(|) operation
    res = x | y;
    cout << res << endl;

    // the not operation

    res = ~x;
    cout << res << endl;

    // the Xor operation
    res = x^y;
    cout << res << endl;

    // left shift operator
    res=x<<1;
    cout<< res<<endl;
    
    //
    res=y>>1;
    cout<< res<<endl;

}