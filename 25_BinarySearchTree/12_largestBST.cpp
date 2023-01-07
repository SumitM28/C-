// find the largest BST in binary tree.
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
class info{
   public:
       int size;
       bool isBST;
       int max;
       int min;
       
};
info solve(Node* root,int &ans){
   if(root==NULL)
       return{0,true,INT8_MIN,INT8_MAX};
   info left=solve(root->left,ans);
   info right=solve(root->right,ans);
   
   info curr;
   curr.min=min(root->data,left.min);
   curr.max=max(root->data,right.max);
   curr.size=left.size+right.size+1;
   if((root->data>left.max && root->data<right.min) && left.isBST && right.isBST)
   {
       curr.isBST=true;
   }
   else
   {
       curr.isBST=false;
   }
   if(curr.isBST)
       ans=max(curr.size,ans);
   return curr;
}

int largestBST(Node* root) 
{
   int ans=0;
   info dummy= solve(root,ans);
   return ans;
   // Write your code here.
}

int main(){
    Node* root;
    takeInput(root);
    levelOrderTraversal(root);
    int ans= largestBST(root);
    cout<<ans<<endl;
}