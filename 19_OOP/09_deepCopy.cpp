// an object is created by copying all the fields, and it also allocate similar memory resources with the same value to the object.
// To perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory as well if required.
#include<iostream>
using namespace std;

class Box{
    private:
    int length;
    int height;

    public:
    int *breadth;
    Box(){
        this->breadth=new int;
    }

    void setValues(int a,int b ,int c){
        length=a;
        *breadth=b;
        height=c;
    }

    void getValue()
    {
        cout << endl;
        cout<<this<<endl;
        cout << "length: " << length << endl;
        cout << "breadth: " << *breadth << endl;
        cout << "heigth: " << height << endl;
    }

    // copy constructor
    Box(const Box & b1){
        length=b1.length;
        breadth=new int;
        *breadth=*(b1.breadth);
        height=b1.height;
    }
    ~Box(){
        delete breadth;
    }
};

int main(){

    Box b1;
    b1.setValues(10,15,20);
    b1.getValue();

    Box b2=b1;
    b2.getValue();
    

    b1.getValue();
    b2.getValue();

}