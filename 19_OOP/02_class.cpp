// in this we will see about dynamically creation of the object.

#include<iostream>
using namespace std;

// class for to find the area of rectangular
class Area{

    public:
    int width;
    int length;
    int printArea(){
        return width * length;
    }
};



int main(){

    Area  *rectangular=new Area;
    
    rectangular->width=10;
    rectangular->length=10;

    cout<<"The area of rectangular is "<<rectangular->printArea()<<endl;


}