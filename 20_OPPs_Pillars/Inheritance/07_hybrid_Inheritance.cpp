/* hybride Inheritance is the combination of more than one type of Inheritacne.
*/

#include<iostream>
using namespace std;
class another{
    public:
    void anotherFun(){
        cout<<"Serve from the another function"<<endl;
    }
};

class parent{
    public:
    void parentFun(){
        cout<<"Serve from the parent class"<<endl;
    }
};

class child1: public parent{
    public:
    void child1Fun(){
        cout<<"Serve from the child1 class"<<endl;
    }
};

class child2: public parent,public another{
    public:
    void child2Fun(){
        cout<<"Serve from the child1 class"<<endl;
    }
};

int main(){

    child2 rishu;
    rishu.child2Fun();
    rishu.parentFun();
    rishu.anotherFun();
}