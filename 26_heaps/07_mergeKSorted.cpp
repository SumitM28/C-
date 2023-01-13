// merge k sorted array
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        node *tmp = new node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }

    vector<int> ans;

    while (minHeap.size() > 0)
    {
        node *temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int row = temp->row;
        int col = temp->col;

        if (col + 1 < kArrays[row].size())
        {
            node *next = new node(kArrays[row][col + 1], row, col + 1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main()
{
    
    vector<vector<int>>kArrays{
        {1, 5, 9},
        {45, 90},
        {2, 6, 78, 100, 234}};
    int k=4;

    vector<int> ans=mergeKSortedArrays(kArrays,k);
    for(auto i: ans){
        cout<<i<<" ";
    }
}