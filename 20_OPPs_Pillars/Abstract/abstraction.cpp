// abstraction is the process of hiding the essensial information.
#include<iostream>
using namespace std;

class Abstraction{
    private:
    int a,b;

    public:
    void setValue(int x,int y){
        a=x;
        b=y;
    }
    void print(){
        cout<<"Value of a "<<a<<" and value of b "<<b;
    }
};

int main(){

    Abstraction obj;
    obj.setValue(2,5);
    obj.print();
}