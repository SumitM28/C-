// doubly ended queue.
#include<bits/stdc++.h>
using namespace std;

class Deque{

    public:
    int *arr;
    int s;
    int front;
    int rear;

    Deque(int n){
        s=n;
        arr=new int[s];
        front=rear=-1;
    }

    void push_front(int data){
        // check full or not
        if(isFull()){
            cout<<"queue is full"<<endl;
        }
        else if(isEmpty()){
            front=rear=0;
        }
        else if(front==0 && rear!=s-1){
            front=s-1;
        }
        else{
            front--;
        }

        arr[front]=data;
    }

    int pop_front(){
        
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int data=arr[front];
        arr[front]=-1;
        
        if(front==rear){
            front=rear=-1;
        }
        else if(front==s-1){
            front=0;
        }
        else{
            front++;
        }

        return data;
    }

    void push_back(int data){
        if(isFull()){
            cout<<"Queue is full"<<endl;
        }
        else if(isEmpty()){
            front=rear=0;
        }
        else if(rear==s-1 && front!=0){
            rear=0;
        }else{
            rear++;
        }
        arr[rear]=data;
    }


    int pop_back(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int data=arr[rear];
        arr[rear]=-1;

        if(front==rear){
            front=rear=-1;
        }

        else if(rear==0){
            rear=s-1;
        }
        else{
            rear--;
        }
        return data;

    }

    int getFront(){
        if(front!=-1){
        return arr[front];

        }else{

            cout<<"Queue is empty"<<endl;
        }
    }

    int getRear(){
        if(rear!=-1){

        return arr[rear];
        }else{
            cout<<"Queue is empty"<<endl;
        }
    }

    bool isEmpty(){
        (front==-1)? true:false;
    }

    bool isFull(){
        if((front==0 && rear==s-1)||(front!=0 && rear==(front-1)%(s-1))){
            return true;
        }else{
            return false;
        }
    }
};


int main(){

    // using STL.
    // deque<int>dq;
    // dq.push_front(1);
    // dq.push_back(2);
    // cout<<dq.front()<<endl;
    // cout<<dq.back()<<endl;

    Deque *q=new Deque(5);
    q->push_front(1);
    q->push_back(2);
    q->push_back(2);
    q->push_back(4);
    cout<<q->getFront()<<endl;
    cout<<q->getRear()<<endl;

}