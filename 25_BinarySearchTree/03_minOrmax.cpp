// find the min or max value in the BST.

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

pair<int,int> minMax(Node *root)
{
    pair<int,int>ans;
    ans.first=INT8_MAX;
    ans.second=INT8_MIN;
    Node* temp=root;
    while (temp!=NULL)
    {
        if(temp->data<ans.first){
            ans.first=temp->data;
        }
        temp=temp->left;
    }
    temp=root;
    while (temp!=NULL)
    {
        if(temp->data > ans.second){
            ans.second=temp->data;
        }
        temp=temp->right;
    }
    return ans;
}

int main()
{
    // 10 8 21 7 27 5 43 -1
    Node *root = NULL;
    cout << "Enter the input:" << endl;
    takeInput(root);
    levelOrderTraversal(root);
    pair<int,int> ans=minMax(root);
    cout<<ans.first<<" "<<ans.second<<endl;
}