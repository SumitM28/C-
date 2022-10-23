// remove duplicate in unsorted linked list.
#include <bits/stdc++.h>
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

Node *removeDuplicate(Node *head)
{

    if (head == NULL)
    {
        return head;
    }
    Node *curr = head;

    // time complexity O(n^2) and space O(1)
    while (curr->next != NULL)
    {
        Node *temp = curr->next;
        while (temp->next != NULL)
        {
            if (temp->next->data == curr->data)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

Node *removeDuplicateOptimize(Node *head)
{

    if (head == NULL)
    {
        return head;
    }

    unordered_map<int,bool>visited;
    Node* prev=NULL;
    Node* curr=head;

    while (curr!=NULL)
    {
        // if node already present 
        if(visited[curr->data]){
            Node* temp=curr;
            prev->next=curr->next;
            curr=curr->next;
            temp->next=NULL;
            delete temp;
        }
        else{
            visited[curr->data]=true;
            prev=curr;
            curr=curr->next;
        }
    }
    
    return head;

}
int main()
{

    LinkedList *LL = new LinkedList();
    LL->addAtHead(3);
    LL->addAtHead(2);
    LL->addAtHead(2);
    LL->addAtHead(4);
    LL->addAtHead(5);
    LL->addAtHead(2);
    LL->addAtHead(4);
    LL->printData();

    Node *head = removeDuplicateOptimize(LL->head);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}