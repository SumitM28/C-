// the basic syntax of the for loop
// sum of all the natural number
#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the Input:";
    cin>>n;

    int sum=0;

    for (int i = 1; i <=n; i++)
    {
        sum+=i;
    }
    
    cout<<sum;

}