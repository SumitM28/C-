// Normal BST To Balanced BST
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

void inOrder(Node* root, vector<int > & v){
    
    if(root==NULL){
        return ;
    }

    inOrder(root->left,v);
    v.push_back(root->data);
    inOrder(root->right,v);
}

Node* solve(vector<int>v ,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(e+s)/2;
    Node* root= new Node(v[mid]);
    root->left=solve(v,s,mid-1);
    root->right=solve(v,mid+1,e);
    return root;
}

Node* balancedBST(Node* root){
    vector<int>inOrderVal;
    inOrder(root,inOrderVal);
    int s=0;
    int e=inOrderVal.size()-1;
    Node* ans=solve(inOrderVal,s,e);
    return ans;
}


int main(){
// 4 2 1 3 5 6 -1
    Node* root=NULL;
    cout<<"Enter the input: ";
    takeInput(root);
    levelOrderTraversal(root);
    Node* ans= balancedBST(root);
    levelOrderTraversal(ans);
    
}

