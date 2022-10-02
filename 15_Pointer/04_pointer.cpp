// pointer and array
#include<iostream>
using namespace std;

int main(){

    // int arr[10]={1,2,3,4,5,6,7};
    
    // // three way to find the address of the first index element.
    // cout<<"The address of the array's 1st element :"<<arr<<endl;
    // cout<<"The address of the array's 1st element :"<<&arr[0]<<endl;
    // cout<<"The address of the array's 1st element :"<<&arr<<endl;


    // cout<<"First element of the array :"<<*arr<<endl;
    // cout<<"add 100 in the 1st element :"<<*arr+100<<endl;
    // cout<<"2nd element of the array :"<<*(arr+1)<<endl;

    // // we can also print a element present in the arr 
    // // we have a formule or a concept that is arr[i]=*(arr+i) work internally. 
    // // where arr[i] indicate the value of present at the adderess arr+i because we already know that is name of array indicate the address of the 1st element.
    // int i=3;
    // cout<<"the "<<i<<"th element is :"<<i[arr]<<endl;

    int temp[10]={1,2,5,6,41};
    
    cout<<"Size of the temp :"<<sizeof(temp)<<endl;
    cout<<"Size of the element :"<<sizeof(*temp)<<endl;
    int *ptr= &temp[0];
    cout<<ptr<<endl;
    cout<<"size of the  element "<<sizeof(*ptr)<<endl;
    cout<<"Size of the pointer address "<<sizeof(&ptr)<<endl;
}