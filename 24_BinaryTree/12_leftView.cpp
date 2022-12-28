#include <iostream>
#include <queue>
#include<map>
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

void solve(Node* root, int lvl, vector<int> &ans){

    // base case
    if(root==NULL){
        return;
    }

    if(lvl==ans.size()){
        // you are enter in new level
        ans.push_back(root->data);
    }

    solve(root->left,lvl+1,ans);
    solve(root->right,lvl+1,ans);
}


vector<int> leftView(Node* root){
    vector<int> ans;
    int lvl=0;
    solve(root,lvl,ans);

    return ans;
}


int main(){

    // 1 2 3 -1 -1 5 -1 -1 4 6 -1 -1 7 -1 -1
    Node* root=NULL;
    root=createTree(root);
    levelOrderTraversal(root);
    cout<<"The bottom view is:"<<endl;
    vector<int> ans=leftView(root);
    for(auto i:ans){
        cout<<i<<" ";
    }

}