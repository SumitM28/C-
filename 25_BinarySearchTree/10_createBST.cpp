// create BST from preorder.
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
Node* solve(vector<int> &preorder,int mini,int maxi,int &i){
//     base case
    if(i>=preorder.size()){
        return NULL;
    }

    
    if(preorder[i]< mini || preorder[i] > maxi){
        return NULL;
    }
    Node* root= new Node(preorder[i++]);
    root->left=solve(preorder,mini,root->data,i);
    root->right=solve(preorder,root->data,maxi,i);
    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int i=0;
    int mini=INT8_MIN;
    int maxi=INT8_MAX;
    return solve(preorder,mini,maxi,i);
    
}

int main(){
    // 4 2 1 3 5 6 -1
    // Node* root=NULL;
    // cout<<"Enter the input: ";
    // takeInput(root);
    cout<<"Enter the input: "<<endl;
    vector<int> preorder;
    
    int i;
    cin>>i;
    while (i!=-1)
    {
        preorder.push_back(i);
        cin>>i;
    }
    
    Node* ans=preorderToBST(preorder);
    levelOrderTraversal(ans);

}