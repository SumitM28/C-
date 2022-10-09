// shallow copy refers to an object
#include <iostream>
using namespace std;

class Box
{

    public:
    int length;
    int breadth;
    int height;

    void setValue(int length, int breadth, int heigth)
    {
        this->length = length;
        this->breadth = breadth;
        this->heigth = height;
    }

    void getValue()
    {
        cout << endl;
        cout<<this<<endl;
        cout << "length: " << length << endl;
        cout << "breadth: " << breadth << endl;
        cout << "heigth: " << height << endl;
    }
};

int main()
{

    Box b1;
    b1.setValue(10, 20, 30);
    Box b2(b1);
    // Box b2 = b1;

    b1.getValue();
    b2.getValue();

    b1.length=100;

    b1.getValue();
    b2.getValue();
}