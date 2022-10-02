// sum of n numbers
#include<iostream>
using namespace std;

int main(){

    int num;
    cout<<"Enter the number:";
    cin>>num;
    int sum=0;
    while (num>0)
    {
        sum+=num;
        num--;
    }

    cout<<"The sum of n number is: "<<sum<<endl;
    
   
    

    
}