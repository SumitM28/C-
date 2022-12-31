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

vector<int> diagonalTraversal(Node *root)
{

    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *currentNode = q.front();
        q.pop();

        while (currentNode)
        {
            ans.push_back(currentNode->data);
            if (currentNode->left != NULL)
            {
                q.push(currentNode->left);
            }
            currentNode=currentNode->right;
        }
    }

    return ans;
}

int main(){

    Node* root=NULL;
    root=createTree(root);
    levelOrderTraversal(root);
    vector<int> ans=diagonalTraversal(root);
    for(auto i:ans){
        cout<<i<< " ";
    }
}