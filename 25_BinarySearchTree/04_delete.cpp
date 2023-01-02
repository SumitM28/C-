// delete a node in BST
#include <iostream>
#include <queue>
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

void insertInBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return;
    }

    if (data < root->data)
    {
        insertInBST(root->left, data);
    }
    if (data > root->data)
    {
        insertInBST(root->right, data);
    }
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertInBST(root, data);
        cin >> data;
    }
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
void *deleteNode(Node* &root, int data)
{
    if (root == NULL || root->data == data)
    {
        root = NULL;
        return 0;
    }
    // if node present in left subtree
    if (root->left->data == data)
    {
        root->left = NULL;
    }
    // if node present in right subtree
    if (root->right->data == data)
    {
        root->left = NULL;
    }

    // check in left subtree
    if (root->data > data)
    {
        deleteNode(root->left, data);
    }
    // checck in right subtree
    if (root->data < data)
    {
        deleteNode(root->right, data);
    }
}

int main()
{
    // 10 8 21 7 27 5 43 -1
    Node *root = NULL;
    cout << "Enter the input:" << endl;
    takeInput(root);
    // levelOrderTraversal(root);
    deleteNode(root, 5);
    levelOrderTraversal(root);
}