// inline function are those function which execute fastly.
#include<iostream>
using namespace std;

// inline fucntion
void update(int &n){
    n=n+1;
 
}

int main(){
    int num=5;
    cout<<num<<endl;
    update(num);
    cout<<num;
}