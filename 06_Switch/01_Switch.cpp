// progrma to switch case
// program find the number in english in a range
#include <iostream>
using namespace std;

int main()
{

    int num;
    cout << "Enter the number:";
    cin >> num;
    char ch='a';

    switch (num)
    {
    case 1:
        cout << "One";
        break;
    case 2:
        cout << "Two";
        break;
    case 3:
        cout << "Three";
        break;
    case 4:
        cout << "Four";
        break;
    case 5:
        cout << "Five";
        break;
    case 6:
        cout << "Six";
        break;
    case 7:
        cout << "Seven";
        break;
    case 8:
        cout << "Eight";
        break;

    case 9:
        switch (ch)
        {
        case 'a':
            cout << "the character is " << ch << endl;
             break;
        }
        break;
    default:
        cout << "Out of the range";
        break;
    }
}