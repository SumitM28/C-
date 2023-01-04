// find kth smallest.
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

int solve(Node *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    int left = solve(root->left, i, k);

    if (left != -1)
    {
        return left;
    }

    i++;
    if (i == k)
    {
        return root->data;
    }

    return solve(root->right, i, k);
}

int kthSmallest(Node *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

int main()
{

    // 4 2 1 3 5 6 -1
    Node *root = NULL;
    cout << "Enter the input:";
    takeInput(root);
    levelOrderTraversal(root);
    int ans = kthSmallest(root,3);
    cout<<ans<<endl;
}