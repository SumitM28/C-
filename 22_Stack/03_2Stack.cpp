// implement two stack in the single array
#include<iostream>
using namespace std;

class TwoStack{
    public:
    int * arr;
    int top1;
    int top2;
    int size;

    TwoStack(int size){
        arr=new int[size];
        top1=-1;
        top2=size;
        this->size=size;
    }

    void push1(int data){

        if(top2-top1>1){
            top1++;
            arr[top1]=data;
        }else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void push2(int data){
        if(top2-top1>1){
            top2--;
            arr[top2]=data;
        }else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    int pop1(){
        if(top1!=-1){
            int ans=arr[top1];
            top1--;
            return ans;
        }else{
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
    }

    int pop2(){
        if(top2!=size){
            int ans=arr[top2];
            top2++;
            return ans;
        }else{
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
    }


};


int main(){

    TwoStack s(5);
    s.push1(1);
    s.push1(2);
    s.push2(3);
    s.push2(4);
    s.push1(5);
    cout<<s.arr[s.top2]<<endl;
    s.pop2();
    cout<<s.arr[s.top2]<<endl;

}