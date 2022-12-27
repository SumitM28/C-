// zig zap traversal.

#include <iostream>
#include <queue>
#include <vector>
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

    cout << "Enter data for left child node of " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter data for right child node of " << data << endl;
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

vector<int> zigZagTraversal(Node *root)
{
    vector<int> result;

    if (root == NULL)
    {
        return result;
    }
    queue<Node *> q;
    q.push(root);
    bool flag = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            int index = flag ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
        flag = !flag;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{

    // 1 2 3 -1 -1 5 -1 -1 4 -1 6 7 -1 -1 8 -1 -1
    Node *root = NULL;
    root = createTree(root);
    levelOrderTraversal(root);
    vector<int> ans = zigZagTraversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}