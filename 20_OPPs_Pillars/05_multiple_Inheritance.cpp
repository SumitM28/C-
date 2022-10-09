/*
when a class inherit more than 1 class is called multilevel inheritance.

*/
#include<iostream>
using namespace std;


class vampire{
    public:
    void bloodSucking(){
        cout<<"vampire can suck blood "<<endl;
    }
};
class warewolf{
    public:
    void bite(){
        cout<<"warewolf can bite"<<endl;
    }
};

class hybride:public vampire,public warewolf{

    public:
    void personality(){
        cout<<"klaus is combination of both"<<endl;
    }
};


int main(){

    hybride klaus;
    klaus.personality();
    klaus.bloodSucking();
    klaus.bite();
    
}