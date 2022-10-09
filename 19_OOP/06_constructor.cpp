// Copy constructor
#include<iostream>
using namespace std;

class constructor{
    int a,b;

    public:
    constructor(int x,int y){
        this->a=x;
        this->b=y;
    }

    constructor(const constructor &p2){
        a=p2.a;
        b=p2.b;
    }

    int getA(){
        return a;
    }
    int getB(){
        return b;
    }
  
};



int main(){

    constructor p1(10,15);
    constructor p2=p1;

    cout<<"p1.a = "<<p1.getA()<<" ,p1.b = "<<p1.getB()<<endl;
    cout<<"p2.a = "<<p1.getA()<<" ,p2.b = "<<p1.getB()<<endl;
}