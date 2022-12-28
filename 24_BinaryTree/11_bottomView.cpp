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

vector<int> bottomView(Node* root){
    vector<int> ans;
    if (root==NULL)
    {
        return ans;
    }

    map<int ,int >bottomNode;
    queue<pair< Node* ,int> >q;

    q.push(make_pair(root,0));

    while (!q.empty())
    {
        pair< Node* ,int> temp=q.front();
        q.pop();

        Node* frontNode=temp.first;
        int hd=temp.second;

        bottomNode[hd]=frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    for(auto i:bottomNode){
        ans.push_back(i.second);
    }
    
    return ans;
}


int main(){

    // 1 2 3 -1 -1 5 -1 -1 4 6 -1 -1 7 -1 -1
    Node* root=NULL;
    root=createTree(root);
    levelOrderTraversal(root);
    cout<<"The bottom view is:"<<endl;
    vector<int> ans=bottomView(root);
    for(auto i:ans){
        cout<<i<<" ";
    }

}