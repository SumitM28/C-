// merge 2 BST
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

// Approach 1 time complexity O(m+n)
// space complexity O(m+n)
void inOrder(Node *root, vector<int> &bst)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, bst);
    bst.push_back(root->data);
    inOrder(root->right, bst);
}
vector<int> merge(vector<int> bst1, vector<int> bst2)
{
    vector<int> ans(bst1.size() + bst2.size());
    int i = 0, j = 0, k = 0;

    while (i < bst1.size() && j < bst2.size())
    {
        if (bst1[i] < bst2[j])
        {
            ans[k++] = bst1[i++];
        }
        else
        {
            ans[k++] = bst2[j++];
        }
    }
    while (i < bst1.size())
    {
        ans[k++] = bst1[i++];
    }
    while (j < bst2.size())
    {
        ans[k++] = bst2[j++];
    }
    return ans;
}
Node *inOrderToBST(int s, int e, vector<int> &mergeInOrder)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    Node *root = new Node(mergeInOrder[mid]);
    root->left = inOrderToBST(s, mid - 1, mergeInOrder);
    root->right = inOrderToBST(mid + 1, e, mergeInOrder);

    return root;
}
Node *mergeBST(Node *root1, Node *root2)
{

    vector<int> bst1, bst2;
    inOrder(root1, bst1);
    inOrder(root2, bst2);

    vector<int> mergeInOrder = merge(bst1, bst2);
    int e = mergeInOrder.size() - 1;
    Node *ans = inOrderToBST(0, e, mergeInOrder);
    return ans;
}

// approach 2
void convertIntoSortedDLL(Node *root, Node *&head)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // right call
    convertIntoSortedDLL(root->right, head);
    root->right = head;

    // check if head is null
    if (head != NULL)
    {
        head->left = root;
    }

    head = root;

    // call for left
    convertIntoSortedDLL(root->left, head);
}

Node *mergeDLL(Node *root1, Node *root2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (root1 != NULL && root2 != NULL)
    {
        if (root1->data < root2->data)
        {

            if (head == NULL)
            {
                head = root1;
                tail = head;
                root1 = root1->right;
            }
            else
            {
                tail->right = root1;
                root1->left = tail;
                tail = root1;
                root1 - root1->right;
            }
        }
        else
        {

            if (head == NULL)
            {
                head = root2;
                tail = head;
                root2 = root2->right;
            }
            else
            {
                tail->right = root2;
                root2->left = tail;
                tail = root2;
                root2 - root2->right;
            }
        }
    }
    while (root1 != NULL)
    {
        tail->right = root1;
        root1->left = tail;
        tail = root1;
        root1 - root1->right;
    }
    while (root1 != NULL)
    {
        tail->right = root1;
        root1->left = tail;
        tail = root1;
        root1 - root1->right;
    }
    return head;
}

int countNodes(Node* head){
    int cnt=0;
    Node* temp=head;
    while (temp!=NULL)
    {
        cnt++;
        temp=temp->right;
    }
    return cnt;
}

Node* sortedDLLtoBST(Node* &head ,int n){

    // base case 
    if(n<=0 || head==NULL){
        return NULL;
    }

    Node* left=sortedDLLtoBST(head,n/2);
    Node* root=head;
    root->left=left;

    head=head->right;

    Node* right=sortedDLLtoBST(head,n-n/2-1);
    return root;
}
int main()
{
    Node *r1 = NULL;
    cout << "Enter input for root 1: ";
    takeInput(r1);

    Node *r2 = NULL;
    cout << "Enter input for root 2: ";
    takeInput(r2);

    levelOrderTraversal(r1);
    levelOrderTraversal(r2);

    Node *ans = mergeBST(r1, r2);
    levelOrderTraversal(ans);
}