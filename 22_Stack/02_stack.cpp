#include <bits/stdc++.h>
using namespace std;

class Stack
{

    // properties
    public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->top = -1;
        this->size = size;
    }

    // behaviour

    void push(int data)
    {
        if (top > size - 1)
        {
            cout << "Stack Overflow"<<endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top != -1)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow"<<endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {   cout<<"stack underflow"<<endl;
            return -1;
        }
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


main()
{

    Stack* s= new Stack(5);

    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    // s->push(5);
    // s->push(5);
    cout<<s->peek();
    cout<<endl;
    s->pop();
    cout<<s->peek();
    cout<<endl;
    if(s->empty()){
        cout<<"stack is empty"<<endl;
    }else{
        cout<<"stack is not empty"<<endl;
    }



}