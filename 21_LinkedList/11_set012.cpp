// sort zeros, ones ,two in the unsorted linked list.
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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

Node* sort012(Node* head){

    int zeros=0,ones=0,two=0;
    Node* temp=head;
    while (temp!=NULL)
    {
        if(temp->data==0){
            zeros++;
        }
        else if(temp->data==1){
            ones++;
        }else{
            two++;
        }
        temp=temp->next;
    }

    temp=head;
    while (zeros)
    {
        temp->data=0;
        zeros--;
        temp=temp->next;
    }
    while (ones)
    {
        temp->data=1;
        ones--;
        temp=temp->next;
    }
    while (two)
    {
        temp->data=2;
        two--;
        temp=temp->next;
    }
    
    return head;
}

void addAtTail(Node* &tail,Node* curr){

    tail->next=curr;
    tail=curr;
}

// when data is not replacable 
Node* sort012Optimize(Node* head){

    Node* zerosHead=new Node(-1);
    Node* zeroTail=zerosHead;
    Node* onesHead=new Node(-1);
    Node* onesTail=onesHead;
    Node* twosHead=new Node(-1);
    Node* towsTail=twosHead;

    Node* curr=head;
    while (curr!=NULL){

        int value=curr->data;
        
        if(value==0){
            addAtTail(zeroTail,curr);
        }
        else if(value==1){
            addAtTail(onesTail,curr);
        }
        else if(value==2){
            addAtTail(towsTail,curr);
        }

        curr=curr->next;
    }

    // if ones linked list is empty 
    if(onesHead->next!=NULL){
        zeroTail->next=onesHead->next;
    }else{
        zeroTail->next=twosHead->next;
    }

    onesTail->next=twosHead->next;
    towsTail->next=NULL;

    head=zerosHead->next;

    // delete dummy node which are -1
    delete zerosHead;
    delete onesHead;
    delete twosHead;
    
    
    return head;
    
}
int main(){

    LinkedList* LL= new LinkedList();
    LL->addAtHead(2);
    LL->addAtHead(0);
    LL->addAtHead(0);
    LL->addAtHead(0);
    LL->addAtHead(1);
    LL->addAtHead(1);
    LL->addAtHead(1);
    LL->addAtHead(2);
    LL->addAtHead(0);
    LL->addAtHead(1);
    LL->addAtHead(1);
    LL->addAtHead(0);
    LL->printData();

    Node* head=sort012Optimize(LL->head);

    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    

}