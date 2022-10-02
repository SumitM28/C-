// reverse the string 
#include<iostream>
#include<vector>
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

// function to reverse the string 

void reverse(char ch[],int n){
    int i=0;
    int j=n-1;

    while (i<=j)
    {
        swap(ch[i],ch[j]);
        i++,j--;
    }
    
}
int main(){

    char ch[15];
    cout<<"Enter the name"<<endl;
    cin>>ch;
    cout<<"Your name is "<<ch<<endl;

    reverse(ch,getLength(ch));
    cout<<ch;
}