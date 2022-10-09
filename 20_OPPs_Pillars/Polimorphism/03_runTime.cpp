// run time polymorphism can be achived by method overlaoding
/*
1.the method of parent class and the method of child class must be same.
2.the method of parent class and the method of child class must have same parameters.
3.it is possible through inheritance
*/
#include<iostream> 
using namespace std;

class Animal{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};
class Dog:public Animal{
    public:
    // void speak(){
    //     cout<<"Barking"<<endl;
    // }
};

int main(){
    Dog tuffy;
    tuffy.speak();
}