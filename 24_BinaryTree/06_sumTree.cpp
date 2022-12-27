// check if the left and right sum of subtree is equal to the current node data for every node.
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

pair<bool, int> isSum(Node *root)
{

    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left=isSum(root->left);
    pair<bool, int> right=isSum(root->right);

    bool checkSum=root->data== left.second + right.second;
    
    bool leftAns=left.first;
    bool rightAns=right.first;

    pair<bool,int>ans;

    if(leftAns && rightAns && checkSum){
        ans.first=true;
        ans.second=2*root->data;
    }else{
        ans.first=false;
    }
    
    return ans;

}

int main()
{

    Node *root = NULL;
    root = createTree(root);
    levelOrderTraversal(root);
    pair<bool,int>ans=isSum(root);
    cout<<ans.first<<endl;
}