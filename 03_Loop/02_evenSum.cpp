// sum of all the even number between n 
#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the last number: ";
    cin>>n;
    int sum=0;
    int i=1;
    while (i<=n)
    {
        if(i%2==0){
            sum+=i;
        }
        i++;
    }
    cout<<sum<<endl;
}