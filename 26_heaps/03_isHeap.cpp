#include <bits/stdc++.h>
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

Node* creationTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for left child node of " << data << endl;
    root->left = creationTree(root->left);
    cout << "Enter data for right child node of " << data << endl;
    root->right = creationTree(root->right);
    return root;
}

// level order traversal

void levelOrder(Node *root)
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

int nodeCount(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int ans = 1 + nodeCount(node->left) + nodeCount(node->right);
    return ans;
}

bool isCBT(struct Node *node, int i, int n)
{
    if (node == NULL)
    {
        return true;
    }

    if (i >= n)
    {
        return false;
    }
    else
    {
        bool left = isCBT(node->left, 2 * i + 1, n);
        bool right = isCBT(node->right, 2 * i + 2, n);

        return (left && right);
    }
}

bool isMaxHeap(struct Node *node)
{
    // check for leaf Node
    if (node->left == NULL && node->right == NULL)
    {
        return true;
    }

    if (node->right == NULL)
    {
        return (node->data > node->left->data);
    }
    else
    {
        bool left = isMaxHeap(node->left);
        bool right = isMaxHeap(node->right);

        return (left && right && (node->data > node->left->data) && (node->data > node->right->data));
    }
}
bool isHeap(struct Node *tree)
{
    // code here
    int index = 0;
    int n = nodeCount(tree);

    return (isCBT(tree, index, n) && isMaxHeap(tree));
}

int main()
{
    // 10 20 40 -1 -1 60 -1 -1 30 -1 -1  --> is not heap
    //  5 2 -1 -1 3 -1 -1 --> is heap
    Node* root;
    root=creationTree(root);
    levelOrder(root);   

    bool ans=isHeap(root);
    if(ans){
        cout<<"Binary tree is a heap"<<endl;
    }else{
        cout<<"Binary tree is not a heap"<<endl;
    }
}