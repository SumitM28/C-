//  Morris travsersal.
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

    cout << "Enter data for left child Node of " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter data for right child Node of " << data << endl;
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
void morrisTraversalPreorder(Node *root)
{
    while (root)
    {
        // If left child is null, print the current Node data. Move to
        // right child.
        if (root->left == NULL)
        {
            cout << root->data << " ";
            root = root->right;
        }
        else
        {
            // Find inorder predecessor
            Node *current = root->left;
            while (current->right && current->right != root)
                current = current->right;

                // If the right child of inorder predecessor already points to
                // this Node
                if (current->right == root)
                {
                    current->right = NULL;
                    root = root->right;
                }

                // If right child doesn't point to this Node, then print this
                // Node and make right child point to this Node
                else
                {
                    cout << root->data << " ";
                    current->right = root;
                    root = root->left;
                }
        }
    }
}

int main()
{

    Node *root;
    root = createTree(root);
    levelOrderTraversal(root);
    morrisTraversalPreorder(root);
}