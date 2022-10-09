/* when the parent calss is inherited by a child class and the child class is alos inherited by a subchild class is called multilevel inheritance.
*/



#include<iostream>
using namespace std;


class Animal{
    public:
    void eat(){
        cout<<"eating"<<endl;
    }
};

class Dog:public Animal{
    public:
    void bark(){
        cout<<"barking"<<endl;
    }
};

class babyDog:public Dog{
    public:
    void weep(){
        cout<<"weeping"<<endl;
    }
};

int main(){

    babyDog puppy;
    puppy.weep();
    puppy.bark();
    puppy.eat();
}