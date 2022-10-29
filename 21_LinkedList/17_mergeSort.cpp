// merge sort on linked list.
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


Node* getMid(Node* head){

    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


Node* merge(Node* left,Node* right){
    if(left==NULL) return right;
    if(right==NULL) return left;

    Node* ans=new Node(-1);
    Node* tail=ans;

    while(left!=NULL && right !=NULL){

        if(left->data<=right->data){
            tail->next=left;
            tail=left;
            left=left->next;
        }else{
            tail->next=right;
            tail=right;
            right=right->next;
        }
    }

    while (left!=NULL)
    {
        tail->next=left;
        tail=left;
        left=left->next;
    }
    
    while (right!=NULL)
    {
        tail->next=right;
        tail=right;
        right=right->next;
    }
    
    ans=ans->next;
    return ans;
}


Node* mergeSort(Node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* mid= getMid(head);
    Node* left=head;
    Node* right=mid->next;
    mid->next=NULL;
    left=mergeSort(left);
    right=mergeSort(right);
    Node* ans=merge(left,right);
    return ans;
}


int main(){

    LinkedList* LL= new LinkedList();
    LL->addAtHead(7);
    LL->addAtHead(1);
    LL->addAtHead(5);
    LL->addAtHead(2);
    LL->addAtHead(8);
    LL->addAtHead(3);
    LL->addAtHead(6);
    LL->addAtHead(9);
    LL->addAtHead(4);
    LL->printData();
    Node* head=LL->head;

    head=mergeSort(head);

    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
    

    

}