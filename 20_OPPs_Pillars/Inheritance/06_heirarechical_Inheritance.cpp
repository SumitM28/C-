/*
when a parent class serve more than one class is called heirarchical inheritance.
*/
#include<iostream>
using namespace std;
class parent{
    public:
    void parentFun(){
        cout<<"Serve from parent class"<<endl;
    }
};

class child1:public parent{
    public:
    void child1Fun(){
        cout<<"Serve from child 1 class"<<endl;
    }
};

class child2:public parent{
    public:
    void child2Fun(){
        cout<<"Serve from child 2 class"<<endl;
    }
};
int main(){

    child1 rishu;
    child2 diya;

    rishu.parentFun();
    rishu.child1Fun();

    diya.parentFun();
    diya.child2Fun();
}