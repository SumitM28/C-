/*
Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.
*/
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

void solve(Node* root, vector<int>path, int k, int &count){
    if(root ==NULL){
        return ;
    }

    path.push_back(root->data);

    solve(root->left,path,k,count);
    solve(root->right,path,k,count);

    int s=path.size();
    int sum=0;
    for(int i=s-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;
        }
    }

    path.pop_back();
}

int ksum(Node* root,int k){
    vector<int>path;
    int count=0;
    solve(root,path,k,count);
    return count;
}

int main(){
    Node* root;
    root=createTree(root);
    levelOrderTraversal(root);

}