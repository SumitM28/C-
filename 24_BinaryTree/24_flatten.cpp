// Flatten a binary tree into a linked list
//  Morris travsersal.
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree(Node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);

    cout << "Enter data for left child Node of " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter data for right child Node of " << data << endl;
    root->right = createTree(root->right);
    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *Flatten(Node *root)
{

    if (root == NULL)
    {
        return root;
    }

    Node *curr = root;

    while (curr != NULL)
    {

        if (curr->left)
        {
            Node *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }

    return root;
}
int main()
{

    Node *root;
    root = createTree(root);
    levelOrderTraversal(root);
    Node *ans = Flatten(root);

    for (ans; ans != NULL; ans = ans->right)
    {
        cout << ans->data << " ";
    }
}