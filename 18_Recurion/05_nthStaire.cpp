/*
you have been given a number of stairs.initially,you are at the 0 stair,and you need to reach the Nth stair.Each time you can either climb one step or two steps. You are supposed to return the number of distinct ways in which you cna climb from the 0th to Nth stpe.
*/

#include<iostream>
using namespace std;

int findWays(int n){

    if(n<0) return 0;
    if(n==0) return 1;

    return findWays(n-1)+findWays(n-2);
}


int main(){

    int nth;
    cout<<"Enter the number of the total stair:";
    cin>>nth;

    cout<<findWays(nth);
}