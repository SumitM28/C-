#include<iostream>
using namespace std;

// function to get the length of the string
int getLength(char ch[]){
    int count=0;

    for (int i = 0; ch[i]!='\0'; i++)
    {
        count++;
    }
    
    return count;
}

int main(){

    char ch[15];
    cout<<"Enter the name"<<endl;
    cin>>ch;
    cout<<"Your name is "<<ch<<endl;

    int size=getLength(ch);
    
    cout<<size<<endl;
}