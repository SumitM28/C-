#include<iostream>
#include<string>
using namespace std;

class Car{

    // public modifier
    public:
    string carName;
    int topSpeed;

    // private modifier 
    private:
    int price=10000;
    public:
    void checkPrice(){
        cout<<price<<" ";
    }


};



int main(){
    // statically object creation

    Car car;
    car.carName="Honda";
    car.topSpeed=120;
    cout<<"The car name is:"<<car.carName<<endl;
    cout<<"The car's top speed is:"<<car.topSpeed<<endl;
    car.checkPrice();

}