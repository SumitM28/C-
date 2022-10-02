/**
 1 2 3 4
 1 2 3 4
 1 2 3 4
 1 2 3 4
 * 
 */

#include<iostream>
using namespace std;

int main(){

    int r,c;
    cout<<"Enter the total rows:";
    cin>>r;
    cout<<"Enter the total coloum:";
    cin>>c;

    for (int i = 1; i <=r; i++)
    {
        for (int j = 1; j<=c; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    



}