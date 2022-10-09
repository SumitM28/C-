/* When a parent class is inherited by only a single child class is called single inheritance.
*/

#include<iostream>
using namespace std;


class Animal{

    public:
    string name;
    int age;

    void printInfo(){
        cout<<"The name of dog is"<<name<<" and the age "<<age<<endl;
    }
    
};

class Dog:public Animal{
    public:
    void bark(){
        cout<<"the dogs are barking";
    }
};

int main(){

    Dog d;
    d.animal="dog";
    d.age=10;
    d.printInfo();
    d.bark();
}