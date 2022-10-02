// program to find the given input is lowecase or uppercase of numeric

#include <iostream>
using namespace std;

int main()
{

    char ch;
    cout << "Enter the character:";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z')
    {
        cout << "UPPER CASE"<<endl;
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        cout << "lowercase"<<endl;
    }
    else if(ch>='1' && ch<='9'){
        cout<<"Numeric"<<endl;
    }
}