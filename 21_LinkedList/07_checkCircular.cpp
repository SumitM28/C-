#include<iostream>
#include<map>
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


    bool checkCircular(){
        if(head==NULL) return false;

        if(head->next==NULL) return false;
        if(head->next==head) return true;

        
        Node* slow=head;
        Node* fast=head;
        while (fast->next->next!=NULL && fast->next!=NULL)
        {
            
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;    
            }
        }

        if(slow==fast && slow==head){
            return true;
        }else{
            return false;
        }
        

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

bool checkcircular(Node* head){
    if(head==NULL){
        return false;
    }
    if(head->next==NULL){
        return false;
    }
    if(head->next==head){
        return true;
    }

    Node* temp=head;

    while (temp!=NULL)
    {
        temp=temp->next;
        if(temp->data==head->data){
            return true;
        }
    }

    return false;
    
}

// by using extra space or hasmap
bool detectLoop(Node* head){
    if(head==NULL){
        return false;
    }

    Node* temp=head;
    map<Node* , bool>visited;

    while (temp!=NULL)
    {
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }

    return false;
    
}
int main(){

    CircularLL* cll= new CircularLL();
    cll->addAthead(5);
    cll->addAthead(4);
    cll->addAthead(3);
    cll->addAthead(2);
    cll->addAthead(1);
    // cll->printData();

    // cout<<cll->checkCircular();
    cout<<detectLoop(cll->head);

}