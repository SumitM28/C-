// clone the linked list
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->random=NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        this->head = NULL;
    }

    void addAtHead(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void printData()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// brute force solution
void addAtTail(Node* &head,int data){

    Node* newNode= new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    
}
Node* cloneLinkedList(Node* head){
    Node* temp=head;
    Node* clone=NULL;

    while (temp!=NULL)
    {
        
        addAtTail(clone,temp->data);
        temp=temp->next;
    }
    
    temp=head;
    Node* cloneTemp=clone;
    
    for ( temp; temp!=NULL; temp=temp->next ,cloneTemp=cloneTemp->next)
    {   
        
        Node* temp2=clone;
    
        while (temp2!=NULL)
        {
            if(temp2->data==temp->random->data){
                cloneTemp->random=temp2;
            }
            temp2=temp2->next;
        }
        

    }
    
    return clone;

}


// optimize solution
Node* cloneLL(Node* head){
    Node* clone=NULL;
    Node* temp=head;
    while (temp!=NULL)
    {
        addAtTail(clone,temp->data);
        temp=temp->next;

    }
    
    map<Node*,Node*>mapping;
    temp=head;
    Node* temp2=clone;
    while (temp!=NULL)
    {
        mapping[temp]=temp2;
        temp=temp->next;
        temp2=temp2->next;
    }
    
    temp=head;
    temp2=clone;
    while(temp2!=NULL){
        temp2->random=mapping[temp->random];
        temp=temp->next;
        temp2=temp2->next;
    }

    return clone;

}
int main(){

    LinkedList* LL= new LinkedList();
    LL->addAtHead(5);
    LL->addAtHead(4);
    LL->addAtHead(3);
    LL->addAtHead(2);
    LL->addAtHead(1);
    Node* head=LL->head;
    head->random=head->next->next;
    head->next->random=head;
    head->next->next->random=head->next->next->next->next;
    head->next->next->next->random=head->next->next;
    head->next->next->next->next->random=head->next;
    
    LL->printData();

    Node* clone=cloneLL(head);
    // while (clone!=NULL)
    // {
    //     cout<<clone->data<<" ";
    //     clone=clone->next;
    // }
    
    cout<<clone->next->random->next->data;
    
}