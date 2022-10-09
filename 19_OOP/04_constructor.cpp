// default cosntructor
#include<iostream>
using namespace std;

class constructor{

    int a,b;

    public:
    constructor(){
        a=10;
        b=25;
    }

    void getValues(){
        cout<<a<<" "<<b;
    }
};



int main(){

    constructor number;
    number.getValues();

}