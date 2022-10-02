// charter array with pointer
#include<iostream>
using namespace std;

int main(){

    char ch[6]="abcde";

    /* it does not print the address of the 1st element.
    it print the whole character array element.-*/
    cout<<ch<<endl;

    // create a pointer 
    char *c=&ch[0];
    cout<<c<<endl;


    char temp='s';
    char *p=&temp;
    cout<<p<<endl;

}