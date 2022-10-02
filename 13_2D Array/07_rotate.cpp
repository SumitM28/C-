// rotate the layer of the matrix by 90 degree.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// rotate function
void rotate(vector<vector<int>> arr)
{
    int n = arr.size();
 
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(arr[i].begin(),arr[i].end());
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j]<<" ";
        }cout<<endl;
    }
}

int main()
{
    vector<vector<int>> arr;

    int row, col;
    cout << "Enter the row:";
    cin >> row;

    cout << "Enter the col:";
    cin >> col;

    cout << "Enter the input:" << endl;
    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            int val;
            cin >> val;
            temp.push_back(val);
        }
        arr.push_back(temp);
    }

    rotate(arr);
}