// reverse the linked list
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

void reverse(Node* &head, Node *curr, Node *&prev)
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

int main()
{

    LinkedList *LL = new LinkedList();
    LL->addATHead(5);
    LL->addATHead(4);
    LL->addATHead(3);
    LL->addATHead(2);
    LL->addATHead(1);

    // LL->reverseLL();
    Node * head=LL->head;
    Node *curr = LL->head;
    Node *prev = NULL;

    LL->reverse(head, curr, prev);
    cout<<prev->data;
    // LL->printData();
}