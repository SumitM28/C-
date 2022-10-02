#include<iostream>
using namespace std;


// update function
void update(int **pt){
    //pt=pt+1;
    // kuch change hoga -- No.
    
    // *pt=*pt+1;
    // ye change kr dega main function me pt1 ki value.

    **pt=**pt+1;
    // ye change krega num ki value .
}
int main(){

    int num=10;
    int *pt1=&num;
    int **pt2=&pt1;

    /*
         710-------  810-------  901
        [10]      |_[710]     |_[810] 
        num         pt1         pt2
    */
    // cout<<"the num is :"<<num<<endl;    // print the value of num.

    // cout<<"address of num :"<<pt1<<endl;    // print the address of num by using pt1.

    // cout<<"The value of *pt1 :"<<*pt1<<endl;     // print the value present at the address of num.

    // cout<<"The address of pt2 :"<<pt2<<endl;    // print the address of pt1 by using pt2.

    // cout<<"The value of *pt2 :"<<*pt2<<endl;     // print the value present at the address of pt1.

    // cout<<"The value of **pt2 :"<<**pt2<<endl;     // pritn the value present at the value of pt1(that is store the address of num).

    cout<<"Before updating the num: "<<num<<endl;
    cout<<"Before updating the pt1: "<<pt1<<endl;
    cout<<"Before updating the pt2: "<<pt2<<endl;

    update(pt2);
    cout<<"After updating the num: "<<num<<endl;
    cout<<"After updating the pt1: "<<pt1<<endl;


}