// find the predecessor and successor.
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

pair<int, int> predecessorSuccessor(Node *root, int key)
{

    pair<int, int> ans;
    int pred = -1;
    int succ = -1;

    Node* temp=root;
    while (temp->data!=key)
    {
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }else{
            pred=temp->data;
            temp=temp->right;
        }

    }

    Node* left=temp->left;
    while (left!=NULL)
    {
        pred=left->data;
        left=left->left;
    }
    Node* right=temp->right;
    while (right!=NULL)
    {
        succ=right->data;
        right=right->left;
    }

    ans = make_pair(pred, succ);
    return ans;
}

int main()
{
    // 4 2 1 3 5 6 -1
    Node *root = NULL;
    cout << "Enter the input:";
    takeInput(root);
    levelOrderTraversal(root);
    pair<int,int >ans=predecessorSuccessor(root,2);
    cout<<ans.first<<" "<<ans.second;
}