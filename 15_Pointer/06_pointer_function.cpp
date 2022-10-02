// pointer and function in cpp

#include<iostream>
using namespace std;

// print funcion
void print(int *p){
    cout<<"Value :"<<*p<<endl;
    cout<<"Adderess :"<<p<<endl;
}

// updata function
void update(int *p){
    int newVal;
    cout<<"Enter the new value :";
    cin>>newVal;
    *p=newVal;
}

// get sum of only three element of the array 
/*
when we pass a array in any function then we does not set the whole array we just send the address.
*/
int getSum(int arr[],int n){

    // cout<<sizeof(arr)<<endl;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=i[arr];
    }
    return sum;
    
}
int main(){


    // int val=5;
    // int *ptr=&val;

    // print(ptr);
    // update(ptr);
    // print(ptr);

    int arr[6]={1,2,3,4,5,6};

    cout<<"Ther sum is :"<<getSum(arr,3);
}