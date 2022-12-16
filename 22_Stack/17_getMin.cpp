#include<iostream>
#include<stack>
using namespace std;

class SpecialStack {
    // Define the data members.
    
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
    stack<int>st;
    int mini;
    
    void push(int data) {
        // Implement the push() function.
        if(st.empty()){
            st.push(data);
            mini=data;
        }else{
            if(data<mini){
                int val=2*data-mini;
                mini=data;
                st.push(val);
            }else{
                st.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if(st.empty()){
            return -1;
        }
        int curr=st.top();
        st.pop();
        if(curr>mini){
            return curr;
        }else{
            int prevMini=mini;
            int val=2*mini-curr;
            mini=val;
            return prevMini;
        }
    }

    int top() {
        // Implement the top() function.
        if(st.empty()){
            return -1;
        }
        int curr=st.top();
        if(curr<mini){
            return mini;
        }else{
            return curr;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return st.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(st.empty()){
            return -1;
        }
        return mini;
    }  
};
int main(){

   SpecialStack *st=new SpecialStack();
   st->push(5);
   st->push(3);
   st->push(8);
   st->push(1);
   st->push(9);
   cout<<st->getMin()<<endl;
   st->pop();
   cout<<st->getMin()<<endl;
   st->pop();
   cout<<st->getMin()<<endl;
    
}