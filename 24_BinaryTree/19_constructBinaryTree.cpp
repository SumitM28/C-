#include <iostream>
#include <queue>
#include <vector>
#include<map>
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

int findPosition(int in[], int n, int data)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == data)
        {
            return i;
        }
    }
    return -1;
}
void creatMapping(int in[],int n,map<int,int> &mp){
    
    for(int i=0;i<n;i++){
        mp[in[i]]=i;
    }
}
Node* solve(int in[], int pre[],int &index,int inOrderStart,int inOrderEnd,int n,map<int,int> mp){
    
    // base case
    if(index >= n || inOrderStart > inOrderEnd) {
        return NULL;
    }
    
    int element=pre[index++];
    Node* root=new Node(element);
    int pos=findPosition(in,n,element);
    
    root->left=solve(in,pre,index,inOrderStart,pos-1,n,mp);
    root->right=solve(in,pre,index,pos+1,inOrderEnd,n,mp);
    
    
    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    map<int,int> mp;
    creatMapping(in,n,mp);
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n,mp);
    return ans;
}

int main()
{
    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};
    int n = 6;
    Node *ans = buildTree(in, pre, n);
    levelOrderTraversal(ans);
}