// flatten the BST into linked list but in sorted order.
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

void inOrder(Node* root, vector<Node* > & v){
    
    if(root==NULL){
        return ;
    }

    inOrder(root->left,v);
    v.push_back(root);
    inOrder(root->right,v);
}

Node* flatten(Node* root){
    vector<Node*>temp;
    inOrder(root,temp);
    root=temp[0];
    Node* curr=root;

    for(int i=1;i<temp.size();i++){
        curr->left=NULL;
        curr->right=temp[i];
        curr=curr->right;
    }
    return root;
}

int main(){
// 4 2 1 3 5 6 -1
    Node* root=NULL;
    cout<<"Enter the input: ";
    takeInput(root);
    // levelOrderTraversal(root);
    Node* ans= flatten(root);
    while (ans!=NULL)
    {
        cout<<ans->data<<" ";
        ans=ans->right;
    }
    
}

