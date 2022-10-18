// circular linked list is in which linked list is in the form of a circular.
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class CircularLL{

    public:
    Node* head;
    Node* tail;

    CircularLL(){
        this->head=NULL;
        this->tail=NULL;
    }

    void addAthead(int data){
        
        Node *newNode= new Node(data);
        if(head==NULL){
            head=newNode;
            tail=head;
            tail->next=head;
            head->prev=tail;
            return;
        }
        newNode->next=head;
        head=newNode;
        tail->next=head;
        head->prev=tail;
    }

    void addAtTail(int data){
        Node* newNode=new Node(data);
        
        if(tail==NULL){
            head=newNode;
            tail=newNode;
            tail->next=head;
            head->prev=tail;
            return ;
        }

        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        tail->next=head;
        head->prev=tail;
    }

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
        tail->next=head;
        head->prev=tail;
    
    }

    // remove at head
    void removeAtHead(){
        head=head->next;
        head->prev=tail;
        tail->next=head;
    }
    // remove at tail
    void removeAtTail(){
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
    }

    // remove at position
    void removeAtPosition(int pos){

        Node* temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        temp->next->next->prev=temp;
        tail->next=head;
        head->prev=tail;
    }
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


    CircularLL* CLL= new CircularLL();
    CLL->addAtTail(4);
    CLL->addAtTail(5);
    CLL->addAtTail(5);
    CLL->addAtTail(5);

    // CLL->printData();

    // CLL->addAtPosition(6,2);
    CLL->removeAtHead();
    CLL->printData();
}   