// height of the tree.

#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
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
            // queue is not empty yet.
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

int height(Node* root){

    if(root==NULL){
        return 0;
    }

    int leftSubTreeHeight=height(root->left);
    int rightSubTreeHeight=height(root->right);

    return max(leftSubTreeHeight,rightSubTreeHeight)+1;
}

int main(){

    Node* root=NULL;
    root=creationTree(root);
    levelOrder(root);
    cout<<"The height of the tree is "<<height(root)<<endl; 
}