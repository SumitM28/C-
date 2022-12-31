// Sum of the longest bloodline of a tree.
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
// approach 1
int longestPathSum(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int ans = root->data;
    int left = longestPathSum(root->left);
    int right = longestPathSum(root->right);

    return max(left, right) + ans;
}
// approach 2
void solve(Node *root, int sum, int &maxSum, int len, int &maxLen)
{

    if (root == NULL)
    {

        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        if (len == maxLen)
        {
            maxSum = max(maxSum, sum);
        }
        return;
    }

    sum = sum + root->data;
    solve(root->left, sum, maxSum, len, maxLen);
    solve(root->right, sum, maxSum, len, maxLen);
}
int sumoflargestPath(Node *root)
{
    int sum = 0;
    int maxSum = 0;
    int len = 0;
    int maxLen = 0;

    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}

// approach 3
vector<int>longRootToLeafPath(Node *root){
        if(root==NULL){
            vector<int>temp = {};
            return temp;
        }
        vector<int>leftvec = longRootToLeafPath(root->left);
        vector<int>rightvec = longRootToLeafPath(root->right);
        if(leftvec.size() > rightvec.size())
            leftvec.push_back(root->data);
        else
            rightvec.push_back(root->data);
        return (leftvec.size() > rightvec.size()?leftvec:rightvec);
    }
int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        if(root==NULL)
            return 0;
        int result=0;
        vector<int>output = longRootToLeafPath(root);
        for(auto i:output){
            result+=i;
        }
        return result;
        
    }

int main()
{
    Node *root = NULL;
    root = createTree(root);
    levelOrderTraversal(root);
    int ans = sumoflargestPath(root);
    cout << ans << endl;
}