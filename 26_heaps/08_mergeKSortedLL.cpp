#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next= NULL;
    }
};
class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};


Node* mergeKLists(vector<Node*> &listArray)
{
    priority_queue<Node* , vector< Node* > , compare > minHeap;
    
    int k = listArray.size();
    if(k==0){
        return NULL;
    }
    
    for(int i=0;i< k;i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }
    Node* head=NULL;
    Node* tail=NULL;    
    while(minHeap.size() > 0){
        Node* top= minHeap.top();
        minHeap.pop();
        
        if(top->next){
            minHeap.push(top->next);
        }
        
        // if ans linked list is empty
        if(head==NULL){
            head=top;
            tail=top;
        }
        
        else{
            tail->next=top;
            tail=top;
        }
    }
    return head;
}