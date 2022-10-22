// find and remove the loop in the linked list.
#include<iostream>
#include<map>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class LinkedList{
    public:
    Node* head;

    LinkedList(){
        this->head=NULL;
    }


    void addAtHead(int data){
        Node* newNode=new Node(data);

        if(head==NULL){
            head=newNode;
            return ;
        }

        newNode->next=head;
        head=newNode;
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

Node* floydDectectLoop(Node* head){
    if(head==NULL) return head;

    Node* slow=head;
    Node* fast= head;

    while (slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast->next!=NULL){
        fast=fast->next;
        }

        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    
    return NULL;
}

Node* findStartingNode(Node* head){

    if(head==NULL){
        return head;
    }

    Node* intersection=floydDectectLoop(head);
    Node* slow=head;

    while (slow!=intersection){
    
        slow=slow->next;
        intersection=intersection->next;
    }
   return slow;
  
    
}

void removeLoop(Node *head){

    Node* startingPoint=findStartingNode(head);
    Node* temp=startingPoint;
    while (temp->next!=startingPoint)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    
}
int main(){

    LinkedList* LL= new LinkedList();
    LL->addAtHead(8);
    LL->addAtHead(7);
    LL->addAtHead(6);
    LL->addAtHead(5);
    LL->addAtHead(4);
    LL->addAtHead(3);
    LL->addAtHead(2);
    LL->addAtHead(1);
    LL->head->next->next->next->next->next->next->next->next=LL->head->next->next->next->next;

    Node* beginNode=findStartingNode(LL->head);
    cout<<beginNode->data<<endl;
    // cout<<floydDectectLoop(LL->head)->data;
    removeLoop(LL->head);
    LL->printData();
    

}