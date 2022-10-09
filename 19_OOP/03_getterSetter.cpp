#include<iostream>
using namespace std;

class Students{

    int health;

    public:
    int getHealth(){
        return health;
    }

    void setHealth(int h){
        health=h;
    }

};



int main(){

    Students *sumit=new Students();
   
    cout<<sumit->getHealth()<<endl;
    sumit->setHealth(25);
    cout<<sumit->getHealth()<<endl;
    
}