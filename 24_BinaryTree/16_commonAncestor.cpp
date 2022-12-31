// lowest common ancestor in binary tree.
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


Node* commonAncestor(Node* root,int n1, int n2){
    // base case
    if(root==NULL){
        return NULL;
    }
    if(root->data == n1 || root->data==n2){
        return root;
    }

    Node* leftAns=commonAncestor(root->left,n1,n2);
    Node* rightAns=commonAncestor(root->right,n1,n2);

    if(leftAns && rightAns){
        return root;
    }
    else if(leftAns !=NULL && rightAns==NULL){
        return leftAns;
    }
    else if(leftAns ==NULL && rightAns !=NULL){
        return rightAns;
    }
    else {
        return NULL;
    }

}


int main(){
    Node* root;
    root=createTree(root);
    levelOrderTraversal(root);
    root=commonAncestor(root,2,3);
    cout<<root->data;

}