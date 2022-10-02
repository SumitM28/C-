// create a program to find the sqrt of a numeber

#include<iostream>
using namespace std;

// binary fuction
int binarySearch(int num){

    int s=0;
    int e=num;
    int mid=s+(e-s)/2;
    int ans=-1;
    while (s<=e)
    {
        int square=mid*mid;
        if((square)==num){
            return mid;
        }
        else if(square<num){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1; 
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){

    int n=100;


    int ans=binarySearch(n);
    cout<<ans<<endl;
}