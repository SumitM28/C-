#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    // constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    
};

class LinkedList{

    public:
    Node* head;
    Node* tail;
    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
    }


    // Insertion at head
    void addATHead(int data){
        // create new node
        Node*  newNode= new Node(data);
        newNode->next=head;
        head= newNode;

        if(tail==NULL){
            tail=head;
            return ;
        }

        
    }


    // Insertion at tail
    void addAtTail(int data){

        Node * newNode= new Node(data);
        if(head==NULL){
            head=newNode;
            tail=head;
            return ;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=newNode;
    }

    // Insertion at middle
    void addAtPosition(int data,int pos){

        Node* newNode= new Node(data);
        Node* temp=head;
        
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;

    }

    // remove at head
    void removeAtHead(){
        head=head->next;
    }


    // remove at tail
    void removeAtTail(){

        Node* temp=head;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }

    // remove at position
    void removeAtPosition(int pos){

       
       
        Node* temp=head;
        temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
       
        temp->next=temp->next->next;

    }
    // print the data of the Linked List or we can say traverse of linked list.
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

    // Node* node1= new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    LinkedList* LLHead = new LinkedList();
    LLHead->addATHead(5);
    LLHead->addATHead(4);
    LLHead->addATHead(3);
    LLHead->printData();
    // LLHead->removeAtTail();
    // LLHead->removeAtPosition(1);
    LLHead->printData();
    cout<<LLHead->tail->data<<endl;


    LinkedList* LLTail = new LinkedList();
    LLTail->addAtTail(1);
    LLTail->addAtTail(2);
    LLTail->addAtTail(3);
    LLTail->addAtPosition(5,2);

    LLTail->printData();
    
    cout<<LLTail->tail->data<<endl;
    
}