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

// level order traversal

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

void inOrder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
}

vector<int> BSTtoMinHeap(Node *root)
{
    vector<int> ans;
    inOrder(root, ans);
    return ans;
}
int main()
{
    // 4 2 1 3 6 5 7 -1
    Node *root = NULL;
    cout << "Enter the input:" << endl;
    takeInput(root);
    levelOrderTraversal(root);
    vector<int> ans = BSTtoMinHeap(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}