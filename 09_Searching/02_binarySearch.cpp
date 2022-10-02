// prgram to binary search

#include<iostream>
using namespace std;


int binarySearch(int arr[],int s,int e,int key){

    while (s<=e)
    {
        int mid= s + ((e-s)/2);

        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            s=mid+1;

        }else{
            e=mid-1;
        }
    }
    return -1;
}
int main(){


    int even[6]={2,4,6,8,12,18};
    int odd[5]={3,8,11,14,16};

    int evenIndex=binarySearch(even,0,5,2);
    cout<<"index of 2 is "<<evenIndex<<endl;

    int oddIndex=binarySearch(odd,0,4,14);
    cout<<"index of 14 is "<<oddIndex<<endl;
}