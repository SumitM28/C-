// remove duplicated from sorted linked list.
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

Node *removeDuplicate(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }
        else
        {

            temp = temp->next;
        }
    }

    return head;
}

int main()
{

    LinkedList *LL = new LinkedList();
    LL->addAtHead(7);
    LL->addAtHead(5);
    LL->addAtHead(5);
    LL->addAtHead(5);
    LL->addAtHead(5);
    LL->addAtHead(5);
    LL->addAtHead(4);
    LL->addAtHead(3);
    LL->addAtHead(3);
    LL->addAtHead(3);
    LL->addAtHead(3);
    LL->addAtHead(2);
    LL->addAtHead(1);
    LL->printData();
    Node *head = removeDuplicate(LL->head);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}