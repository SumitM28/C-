// check palidrome given linked list
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

bool checkPalidrome(Node* head){

    vector<int>v;
    while(head!=NULL){
        v.push_back(head->data);
        head=head->next;
    }

    int s=0,e=v.size()-1;
    while (s<=e)
    {
        if(v[s]!=v[e]){
            return false;
        }
        s++,e--;
    }
    return true;
    
}

// Optimize approach

Node* getMid(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while (fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
    
}

Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL){
        Node* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }

    return prev;
}

bool isPalidrome(Node* head){
    if(head->next==NULL){
        return true;
    }

    // get middle of the linked list.
    Node* middle=getMid(head);

    // reverse the part after middle.
    middle->next=reverse(middle->next);

    // compare both part
    Node* head1=head;
    Node* head2=middle->next;

    while (head2!=NULL )
    {
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    
    middle->next=reverse(middle->next);
    return true;
}

int main(){

    LinkedList* LL= new LinkedList();
    LL->addAtHead(1);
    LL->addAtHead(2);
    LL->addAtHead(2);
    LL->addAtHead(2);
    LL->addAtHead(1);
    LL->addAtHead(1);
    LL->printData();

    bool ans=isPalidrome(LL->head);
    cout<<ans<<endl;
}