//  burn a tree in minimum time.
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

Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{

    Node *res = NULL;
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {

        Node *front = q.front();
        q.pop();

        // target node
        if (front->data == target)
        {
            res = front;
        }

        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    map<Node *, bool> visited;
    visited[root] = true;
    queue<Node *> q;
    q.push(root);
    int time = 0;
    while (!q.empty())
    {

        bool flag = false;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if (flag)
        {
            time++;
        }
    }
    return time;
}
int minTime(Node *root, int target)
{
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(root, target, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}

int main(){
// 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    Node* root=NULL;
    root=createTree(root);
    levelOrderTraversal(root);
    cout<<"Your output: ";
    int ans=minTime(root,8);
    cout<<ans;
}