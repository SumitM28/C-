// constructor is the special member of the class which is called when the object is created.
// this is the parameter constructor.

#include<iostream>
#include<string>
using namespace std;

class Students{
    private:
    string name;
    int age;

    public:
    Students(string name,int age){
        this->name=name;
        this->age=age;
    }

    string getName(){
        return name;
    }

    int getAge(){
        return age;
    }
};


int main(){

    // Students sumit("sumit",19);
    // cout<<sumit.getName()<<endl;
    // cout<<sumit.getAge()<<endl;
    
    Students *sumit=new Students("Sumit",19);
    cout<<sumit->getName()<<endl;
    cout<<sumit->getAge()<<endl;
}