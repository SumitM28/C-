// reverse the linked list in k group 
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
    Node *tail;
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void addATHead(int data)
    {
        // create new node
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;

        if (tail == NULL)
        {
            tail = head;
            return;
        }
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

Node* reverseK(Node* head,int k){
    
    // when head is null
    if(head==NULL){
        return head;
    }

    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;
    int count=0;
    while (curr!=NULL && count<k)
    {
        count++;
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }

    if(forward!=NULL){
        head->next=reverseK(forward,k);
    }
    
    return prev;


}

int main(){
    LinkedList* LL= new LinkedList();
    LL->addATHead(11);
    LL->addATHead(9);
    LL->addATHead(8);
    LL->addATHead(7);
    LL->addATHead(2);
    LL->addATHead(3);

    LL->printData();
    int k=2;
    
    Node* head=reverseK(LL->head,k);
    // cout<<head->next->data;
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}