// find two sum of the BST if it is exist.
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

void inOrder(Node* root, vector<int> & v){
    
    if(root==NULL){
        return ;
    }

    inOrder(root->left,v);
    v.push_back(root->data);
    inOrder(root->right,v);
}



pair<int ,int> twoSum(Node* root,int data){
    vector<int>temp;
    inOrder(root,temp);
    cout<<temp[0]<<" "<<temp[temp.size()-1]<<endl;
    pair<int ,int> ans;
    int i=0,j=temp.size()-1;
    while (i < j)
    {
        if(temp[i]+temp[j]==data){
            ans=make_pair(temp[i++],temp[j--]);
            
        }
        else if(temp[i]+temp[j] > data){
            j--;
        }
        else if(temp[i]+temp[j] < data){
            i++;
        }
    }
    return ans;
}

int main(){
    Node* root=NULL;
    cout<<"Enter the data:";
    takeInput(root);
    levelOrderTraversal(root);
    pair<int ,int> ans=twoSum(root,10);
    cout<<ans.first<<" "<<ans.second<<endl;
}