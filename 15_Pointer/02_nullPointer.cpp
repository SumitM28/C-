// null pointer .

#include<iostream>
using namespace std;

int main(){
    // null pointer.
    int *ptr=NULL;
    int num=5;
    ptr=&num;
    

    // coping pointer in another pointer
    int *ptr2=ptr;
    cout<<ptr<<" - "<<ptr2<<endl;
    cout<<*ptr<<" - "<<*ptr2<<endl;

    // pointer arithimetic
    int i=3;
    int *t=&i;
    (*t)++;
    cout<<*t<<endl;

    cout<<"Before :"<<t<<endl;
    // if we did this the pointer will move one address 
    t=t+1;
    cout<<"After :"<<t<<endl;

}