#include<iostream>
using namespace std;

string number[]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};

void sayDigit(int n){
   
    if(n==0){
        return ;
    }

    int digit=n%10;
    n/=10;
    sayDigit(n);
    cout<<number[digit]<<" ";
}



int main(){


    int num;
    cout<<"Enter the number:";
    cin>>num;

    sayDigit(num);
   
}