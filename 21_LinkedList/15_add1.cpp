// add one in number represented by linked list.
#include<iostream>
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

Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;

    while (curr!=NULL)
    {
        Node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;

    }
    
    return prev;
}


Node* add1(Node* head){

    head=reverse(head);
    int carry=0;
    Node* ans=NULL;
    int val2=1;
    while (head !=NULL|| carry!=0)
    {
        int val1=0;
        if(head!=NULL){
            val1=head->data;
        }
        
        int sum=val1+val2+carry;
        int digit=sum%10;
        val2=0;

        // add the data at the head.
        Node* newNode= new Node(digit);
        newNode->next=ans;
        ans=newNode;


        // increasing the pointer.        
        carry=sum/10;


        if(head!=NULL){
            head=head->next;
        }

    
    }

    return ans;
}

int main(){

    LinkedList* LL= new LinkedList();
    LL->addAtHead(1);
    LL->addAtHead(9);
    LL->addAtHead(9);

    Node* ans= add1(LL->head);

    while (ans!=NULL)
    {
        cout<<ans->data<<" ";
        ans=ans->next;
    }
}