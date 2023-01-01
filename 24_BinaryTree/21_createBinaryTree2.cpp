//  create a binary tree you have given in order and and post order array.

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

int findPosition(int in[], int data, int n)
{

    for (int i = 0; i < n; i++)
    {

        if (in[i] == data)
        {
            return i;
        }
    }
    return -1;
}
void creatMapping(int in[], int n, map<int, int> &mp)
{

    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
}
Node *solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n)
{

    // base case
    if (index < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = post[index--];
    Node *root = new Node(element);
    int pos = findPosition(in, element, n);

    root->right = solve(in, post, index, pos + 1, inOrderEnd, n);
    root->left = solve(in, post, index, inOrderStart, pos - 1, n);

    return root;
}

// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{

    int postOrderindex = n - 1;
    Node *ans = solve(in, post, postOrderindex, 0, n - 1, n);
    return ans;
}

int main()
{
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int pre[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = 8;
    Node *ans = buildTree(in, pre, n);
    levelOrderTraversal(ans);
}