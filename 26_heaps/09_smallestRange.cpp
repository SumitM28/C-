// find smallest range from the k sorted list.
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;
    node(int data,int row,int col){
        this->data=data;
        this->row=row;
        this->col=col;
    }
    
};
class compare{
    public:
        bool operator()(node * a,node *b){
            return a->data > b->data;
        }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
   priority_queue<node*,vector<node*>,compare>minheap;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    //pushing all the 1st elements of k arrays to MINHEAP
    //alse keep tracks of minimum and maximum
    for(int i=0;i<k;i++){
        int element=a[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        minheap.push(new node(element,i,0));
    }
    int start=mini,end=maxi;
    while(!minheap.empty()){
        node * top=minheap.top();
        minheap.pop();
        int col=top->col;
        int row=top->row;
        mini=top->data;
        //checking if new min amd max is less than previous range
        if(maxi-mini<end-start){
            start=mini;
            end=maxi;
        }
        //checking if the current minimum elemnt has right index
        //also updates the maximum element too
        if(top->col+1<n){
            maxi=max(a[row][col+1],maxi);
            minheap.push(new node(a[top->row][top->col+1],top->row,top->col+1));
        }
        //this is crucial as any of k array goes out of bound ,further checking would not contain all elements in it.
        else{
            break;
        }
    }
    return end-start+1;
}

int main(){
    vector<vector<int>> a{
        {4, 7, 30},
        {1, 2, 12},
        {20, 40, 50}

    };
    int k=3,n=3;
    int ans=kSorted(a,k,n);
    cout<<ans;
}