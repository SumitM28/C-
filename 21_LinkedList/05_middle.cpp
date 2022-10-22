// find the middle of the linked list
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

    void reverseLL()
    {

        // when linked list is empty or one element
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        Node *prev = NULL;
        Node *curr = head;
        Node *temp = head;

        while (curr != NULL)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }

    void reverse(Node *&head, Node *curr, Node *&prev)
    {

        if (curr == NULL)
        {
            head = prev;
            return;
        }

        Node *forward = curr->next;
        reverse(head, forward, prev);
        curr->next = prev;
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

int findMiddle(Node* head){
    Node* temp=head;
    int n=0;
    while (temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    temp=head;

    for (int i = 0; i < n/2; i++)
    {
        temp=temp->next;
    }
    

    return temp->data;
    // return n;
    
    
}

int getMiddle(Node* head){

    // if head is null or single node
    if(head==NULL ||head->next==NULL){
        return head->data;
    }
    // 2 node
    if(head->next->next==NULL){
        return head->next->data;
    }

    Node* slow=head;
    Node* fast=head->next;

    while (fast!=NULL)
    {   
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        
    }
    return slow->data;
    
}
int main(){ 

    LinkedList* LL= new LinkedList();
    // LL->addATHead(5);
    LL->addATHead(4);
    LL->addATHead(3);
    LL->addATHead(2);
    LL->addATHead(1);

    LL->printData();

    int mid=getMiddle(LL->head);
    cout<<mid;
    
}