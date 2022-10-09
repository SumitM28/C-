// destructor is the special member of class that is used to destroy or delete the class. 
#include<iostream>
#include<string>
using namespace std;

class Students{

    string name;
    int age;

    public:
    Students(string name,int age){
        cout<<"Construtor is called"<<endl;
        this->name=name;
        this->age=age;
    }

    void getInfo(){
        cout<<this->name<<" "<<this->age<<endl;
    }

    ~Students(){
        cout<<"Deostrutor is called"<<endl;
    }
};



int main(){

    Students sumit("Sumit",19);
    sumit.getInfo();
}

