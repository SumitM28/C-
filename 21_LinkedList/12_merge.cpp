// merge 2 sorted Linked list
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


// bruteforce approach
Node* mergeSortLL(Node* head1,Node* head2){

    if(head1->next==NULL){
        head1->next=head2;
        return head1;
    }

    Node* head= new Node(-1);
    Node* tail=head;

    while (head1!=NULL && head2!=NULL)
    {
        if(head1->data<=head2->data){
            Node* newNode=new Node(head1->data);
            tail->next=newNode;
            tail=newNode;
            head1=head1->next;
        }else{
            Node* newNode=new Node(head2->data);
            tail->next=newNode;
            tail=newNode;
            head2=head2->next;
        }
        
    }
    
    while (head1!=NULL)
    {
        Node* newNode=new Node(head1->data);
        tail->next=newNode;
        tail=newNode;
        head1=head1->next;
    }
    
    while (head2!=NULL)
    {
        Node* newNode=new Node(head2->data);
        tail->next=newNode;
        tail=newNode;
        head2=head2->next;
    }

    return head->next;
  
    
}

Node* mergeLL(Node* head1,Node* head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    if(head1->data<=head2->data){
        return mergeSortLL(head1,head2);
    }else{
        return mergeSortLL(head2,head1);
    }
}


// optimize solution
Node* solve(Node* first,Node* second){


    // when first list contain only single node
    if(first->next==NULL){
        first->next=second;
        return first;
    }
    Node* curr1=first;
    Node* next1=curr1->next;
    Node* curr2=second;
    Node* next2=curr2->next;

    while (next1!=NULL && curr2!=NULL)
    {

        if(curr2->data>=curr1->data && curr2->data<=next1->data){
            // add node between the nodes
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            // increment the pointers
            curr1=curr2;
            curr2=next2;
        }else{
            curr1=next1;
            next1=next1->next;

            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
        
    }
    
    return first;
}


Node* merge(Node* head1,Node*head2){

    if(head1==NULL) return head2;

    if(head2==NULL) return head1;

    if(head1->data<=head2->data){
        return solve(head1,head2);
    }else{
        return solve(head2,head1);
    }
}
int main(){

    LinkedList* head1=new LinkedList();
    head1->addAtHead(5);
    head1->addAtHead(4);
    head1->addAtHead(1);
    LinkedList* head2=new LinkedList();
    head2->addAtHead(5);
    head2->addAtHead(3);
    head2->addAtHead(2);

    head1->printData();
    head2->printData();

    Node* head=mergeLL(head1->head,head2->head);

    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}