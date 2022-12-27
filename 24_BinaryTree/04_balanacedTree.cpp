// check the given tree is balanced or not.
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* createTree(Node* root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }
    root= new Node(data);

    cout << "Enter data for left child node of " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter data for right child node of " << data << endl;
    root->right = createTree(root->right);
    return root;
    
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{

            cout<<temp->data<< " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }

        }
    }
    
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int left=height(root->left);
    int right=height(root->right);

    return max(left,right)+1;
}

// time complexity O(n^2)
bool checkBalanced(Node* root){

    if(root==NULL){
        return true;
    }

    bool left=checkBalanced(root->left);
    bool right=checkBalanced(root->right);

    bool third=abs(height(root->left)-height(root->right))<=1;

    if(left && right && third){
        return true;
    }else{
        return false;
    }
}


// time complexity O(n)
pair<bool,int> checkBalancedOptimised(Node *root){

    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }

    pair<bool,int> left=checkBalancedOptimised(root->left);
    pair<bool,int> right=checkBalancedOptimised(root->right);

    bool leftAns=left.first;
    bool rightAns=right.first;
    bool third=abs(left.second-right.second)<=1;

    pair<bool,int>ans;
    ans.second=max(left.second,right.second)+1;
    
    ans.first=(leftAns && rightAns && third)?true:false;
    return ans;
}

int main(){

    Node* root=NULL;
    root=createTree(root);
    levelOrderTraversal(root);
    pair<bool,int>ans =checkBalancedOptimised(root);
    cout<<ans.second<<endl;
}