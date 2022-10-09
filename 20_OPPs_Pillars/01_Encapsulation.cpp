// Encapsulation is the process to wrapping the data members and the method inside a single unit.
#include<iostream>
using namespace std;

class Student{

    private:
    string name;
    int rollNo;
    int age;

    public:
    
    void setInfo(string name,int rollNo,int age){
        this->name=name;
        this->rollNo=rollNo;
        this->age=age;
    }

    string getName(){
        return name;
    }

    int getRoll(){
        return rollNo;
    }
    int getAge(){
        return age;
    }


};


int main(){

    Student first;
    first.setInfo("Sumit",42,19);
    cout<<"Student Name: "<<first.getName()<<endl;
    cout<<"Student Roll No: "<<first.getRoll()<<endl;
    cout<<"Student Age: "<<first.getAge()<<endl;
}