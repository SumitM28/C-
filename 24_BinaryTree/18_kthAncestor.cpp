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
Node* solve(Node* root,int &k,int node){

    // base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }

    Node* leftAns=solve(root->left,k,node);
    Node* rightAns=solve(root->right,k,node);

    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k<=0){
            k=INT8_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns==NULL && rightAns!=NULL){
        k--;
        if(k<=0){
            k=INT8_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans=solve(root,k,node);
    if(ans==NULL || ans->data==node){
        return -1;
    }else{
        return ans->data;
    }
}


int main(){

    Node* root;
    root=createTree(root);
    levelOrderTraversal(root);
    int ans=kthAncestor(root,2,4);
    cout<<ans;
}