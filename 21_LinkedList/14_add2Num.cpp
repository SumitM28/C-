// add two number represented by linked list.
#include <iostream>
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

Node* add2LL(Node* head1, Node* head2){

    head1=reverse(head1);
    head2=reverse(head2);
    int carry=0;
    Node* ans=NULL;

    while (head1 !=NULL || head2!=NULL || carry!=0)
    {
        int val1=0;
        if(head1!=NULL){
            val1=head1->data;
        }
        int val2=0;
        if(head2!=NULL){
            val2=head2->data;

        }
        int sum=val1+val2+carry;
        int digit=sum%10;

        // add the data at the head.
        Node* newNode= new Node(digit);
        newNode->next=ans;
        ans=newNode;


        // increasing the pointer.        
        carry=sum/10;


        if(head1!=NULL){
            head1=head1->next;
        }

        if(head2!=NULL){
            head2=head2->next;
        }

    
    }

    return ans;
}

int main()
{

    LinkedList* LL1= new LinkedList();
    LL1->addAtHead(4);
    LL1->addAtHead(3);
    LL1->addAtHead(3);
    LL1->addAtHead(3);
    LL1->addAtHead(3);
    LL1->printData();
    LinkedList* LL2= new LinkedList();
    LL2->addAtHead(0);
    LL2->addAtHead(3);
    LL2->addAtHead(2);
    LL2->printData();


    Node* ans= add2LL(LL1->head,LL2->head);

    while (ans!=NULL)
    {
        cout<<ans->data<<" ";
        ans=ans->next;
    }
    
    
}