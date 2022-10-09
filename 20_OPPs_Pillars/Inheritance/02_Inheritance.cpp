// inheritance is the process to inherit the parent's calss properties by a child class.
#include<iostream>
using namespace std;

class Human{
    public:
    int hieght;
    int weight;
    int age;

    int getHieght(){
        return this->hieght;
    }

    int getWeight(){
        return this->weight;
    }

    int getAge(){
        return this->hieght;
    }
};

class Male:public Human{
    public:
    string color;

    void sleep(){
     cout<<"Male Sleeping";   
    cout<<hieght<<endl;
    }

};


int main(){

    Male obj1;

  
    obj1.hieght=165;
    obj1.age=19;
    obj1.weight=65;

    cout<<"Hieght :"<<obj1.getHieght()<<endl;
    cout<<"Weight :"<<obj1.getWeight()<<endl;
    cout<<"age :"<<obj1.getAge()<<endl;

    // child class
    obj1.color="brown";
    obj1.sleep();
   


}