// vertical traversal of a binary tree.

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
vector<int> verticalTraversal(Node *root)
{
    vector<int> ans;
    map<int, map<int, vector<int> > > nodes;
    queue<pair<Node *, pair<int, int> > > q;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int> > temp=q.front();
        q.pop();
        Node* frontNode=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;

        // push in the nodes
        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
        }
    }

    for(auto i:nodes){

        for(auto j:i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{
    // 1  2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
    Node* root=NULL;
    root=createTree(root);
    levelOrderTraversal(root);
    vector<int> ans=verticalTraversal(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
}