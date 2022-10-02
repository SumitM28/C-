// create a program to check the number is prime

#include<iostream>
using namespace std;


int checkPrime(int n){
    if(n==2){
        return 1;
    }

    for (int i = 2; i < n; i++)
    {
        if(n%i==0){
            return 0;
        }
    }
    return 1;

}
int main(){

    int num;
    cout<<"Enter the number: ";
    cin>>num;

    int ans=checkPrime(num);

    if(ans==true){
        cout<<"prime.";
    }else{
        cout<<"Not prime.";
    }


}