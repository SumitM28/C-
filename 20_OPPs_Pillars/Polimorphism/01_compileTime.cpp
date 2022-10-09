// compile time polymorphysm can be achived by the 
// function overloading 
// operator over loading

// in this we will see function overloading
#include<iostream> 
using namespace std;

class Addition{
    public:
    
    int add(int a, int b){
        return a+b;
    }

    // overloading by using different no of arguments
    int add(int a,int b,int c){
        return a+b+c;
    }
};

class Subtraction{
    public:

    int sub(int a,int b){
        return a-b;
    }

    double sub(double a,double b){
        return a-b;
    }
};

int main(){
    Addition value;
    cout<<value.add(20,10)<<endl;
    cout<<value.add(10,20,30)<<endl;


    Subtraction value2;
    cout<<value2.sub(30,20)<<endl;
    cout<<value2.sub(30,10)<<endl;
}