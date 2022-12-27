// diameter of the tree.
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



int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=diameter(root->left);
    int right=diameter(root->right);
    int both=height(root->left)+1+height(root->right);

    return max(left, max(right,both));
}

pair<int,int> diameterFast(Node *root){

    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    pair<int,int> left=diameterFast(root->left);
    pair<int,int> right=diameterFast(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+left.second+1;

    pair<int,int>ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;

}

int main(){

    Node* root=NULL;
    root=createTree(root);
    levelOrderTraversal(root);
    // cout<<diameter(root);
    pair<int,int>ans=diameterFast(root);
    cout<<ans.first;
}