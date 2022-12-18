#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // enqueue or push
    bool enqueue(int data)
    {
        // check is queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))){
            cout<<"Queue is full"<<endl;
            return false;
        }
        // push first element
        else if(front==-1){
            front=rear=0;
            // arr[rear]=data;
        }
        // when space is free before front
        else if( rear==size-1 && front!=0){
            rear=0;
            // arr[rear]=data;
        }
        // normal push
        else{
            rear++;
            // arr[rear]=data;
        }
        arr[rear]=data;
        return true;
    }

    int dequeue(){
        // if queue is empty.
        if(front==-1){
            cout<<"Queue is underflow"<<endl;
            return -1;
        }

        int data=arr[front];
        arr[front]=-1;
        // when only single element is present.
        if(front==rear){
            
            front=rear=-1;
        }

        // when element are already present before the front.
        else if(front==size-1){
            
            front=0;
        }
        // normal push
        else{
            front++;
        }

        return data;
    }
};

int
main()
{

    CircularQueue *q=new CircularQueue(5);
    q->enqueue(1);
    q->enqueue(2);
    cout<<q->dequeue();
}