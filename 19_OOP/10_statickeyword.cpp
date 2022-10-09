// static keyword can be access withourt create any object.
// static function can only access the static varialbe .
#include <iostream>
using namespace std;

class Box
{

    public:
    int length;
    int breadth;
    int height;
    static int timeToComplete;

    void setValue(int length, int breadth, int heigth)
    {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    void getValue()
    {
        cout << endl;
        cout<<this<<endl;
        cout << "length: " << length << endl;
        cout << "breadth: " << breadth << endl;
        cout << "heigth: " << height << endl;
    }

    static int random(){
        return timeToComplete;
    }    
    
    
};


int Box::timeToComplete=15;
int main()
{
    cout<<Box::timeToComplete<<endl;
    cout<<Box::random()<<endl;

    // Box b1;
    // b1.setValue(10, 20, 30);
    // Box b2(b1);
    // // Box b2 = b1;

    // b1.getValue();
    // b2.getValue();

    // b1.length=100;

    // b1.getValue();
    // b2.getValue();
}