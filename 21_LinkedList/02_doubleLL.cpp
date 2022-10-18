// doubly linked's node have data, address of previous node and the address of next node.
#include<iostream>
using namespace std;
class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

class doubleLL{
    public:
    Node* head;
    Node* tail;

    doubleLL(){
        this->head=NULL;
        this->tail=NULL;
    }

    // add node at head
    void addTohead(int data){

        Node* newNode=new Node(data);

        if(head==NULL){
            head=newNode;
            tail=head;
            return;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }

    // add at tail
    void addAtTail(int data){
        Node* newNode=new Node(data);
        
        if(tail==NULL){
            head=newNode;
            tail=newNode;
            return ;
        }

        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    //add at the position
    void addAtPosition(int data,int pos){
        Node* newNode= new Node(data);
        
        Node* temp=head;
        
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next->prev=newNode;
        temp->next=newNode;
        newNode->prev=temp;
    
    }

    // remove at head
    void removeAtHead(){
        head=head->next;
        head->prev=NULL;
    }
    // remove at tail
    void removeAtTail(){
        tail=tail->prev;
        tail->next=NULL;
    }

    // remove at position
    void removeAtPosition(int pos){

        Node* temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        temp->next->next->prev=temp;
        
    }
    // print the data
    void printData(){
  
        Node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<endl;

    }
};


int main(){


    doubleLL* dLL=new doubleLL();


    // adding node at the head
    // dLL->addTohead(5);
    // dLL->addTohead(4);
    // dLL->addTohead(3);
    // dLL->addTohead(2);
    // dLL->addTohead(1);
    
    // adding node at the tail

    dLL->addAtTail(1);
    dLL->addAtTail(2);
    dLL->addAtTail(3);
    dLL->addAtTail(4);
    dLL->addAtPosition(5,3);
    dLL->printData();
    // dLL->removeAtHead();
    // dLL->removeAtTail();
    dLL->removeAtPosition(3);
    dLL->printData();

    // cout<<dLL->head->data<<" "<<dLL->tail->data;

}
