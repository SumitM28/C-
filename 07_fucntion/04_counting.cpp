// create a program to print the counting

#include<iostream>
using namespace std;

void printCoutning(int n){

    for (int i = 1; i <=n; i++)
    {
        cout<<i<<" ";
    }
    

}

int main(){

    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    printCoutning(n);
}