// you are given 2 tree check if both tree are identicle or not.
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

bool checkIdenticle(Node* r1,Node* r2){

    // if both are null
    if(r1==NULL && r2 ==NULL){
        return true;
    }
    if(r1==NULL && r2!= NULL){
        return false;
    }
    if(r1!=NULL && r2== NULL){
        return false;
    }

    bool left=checkIdenticle(r1->left,r2->left);
    bool right=checkIdenticle(r1->right,r2->right);
    
    bool value = r1->data == r2->data;

    return (left,right,value)?true:false;
}

int main(){
    Node* r1=NULL;
    Node *r2=NULL;
    r1=createTree(r1);
    r2=createTree(r2);
    levelOrderTraversal(r1);
    levelOrderTraversal(r2);
    cout<<checkIdenticle(r1,r2);
}