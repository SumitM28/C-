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

Node* findMini(Node* root){
    while (root->left!=NULL)
    {
        root=root->left;
    }

    return root;
    
}
Node *deleteFromBST(Node *root, int data)
{

    if (root == NULL)
    {
        return root;
    }

    if (root->data == data)
    {

        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // only left child exist
        if (root->left !=NULL && root->right == NULL)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        // only right child exist
        if (root->right!=NULL && root->left == NULL)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left !=NULL && root->right !=NULL)
        {
            int mini=findMini(root->right) -> data;
            root->data=mini;
            root->right= deleteFromBST(root->right,mini);
            return root; 
        }
    }
    else if (root->data > data)
    {
        // check in left part
        deleteFromBST(root->left, data);
    }
    else
    {
        // check in right part
        deleteFromBST(root->right, data);
    }

    return root;
}

int main()
{
    // 10 8 21 7 27 5 43 -1
    Node *root = NULL;
    cout << "Enter the input:" << endl;
    takeInput(root);
    levelOrderTraversal(root);
    deleteFromBST(root, 5);
    levelOrderTraversal(root);

}