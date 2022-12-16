#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int front;
    int rear;
    int s;
    Queue(int size){
        arr=new int[size];
        s=size;
        front=0;
        rear=0;
    }
    void push(int data){
        if(rear==s){
            cout<<"Queue is overflow"<<endl;
            return;
        }
        else{
            arr[rear]=data;
            rear++;
        }

    }

    int pop(){
        if(front==rear){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        int data=arr[front];
        for (int i = 0; i <=rear; i++)
        {
            arr[i]=arr[i+1];
        }
        rear--;
        return data;
    }

    int top(){
        return arr[front];
    }

    bool isempty(){
        return (front==rear)? true:false;
    }
};



int main(){

    Queue *q = new Queue(5);
    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(5);
    cout<<q->pop()<<endl;
    q->pop();
    cout<<q->top();

    queue<int>queue;

}