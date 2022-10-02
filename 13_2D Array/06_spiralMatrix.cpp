// print the spiral metrix.

#include <iostream>
#include <vector>
using namespace std;


vector<int> spiralOrder(vector<vector<int>> arr)
{
    vector<int> ans;

    int left = 0;
    int right = arr[0].size() - 1;
    int top = 0;
    int down = arr.size() - 1;
    int pos = 1;

    while (left <= right && top <= down)
    {

        if (pos == 1)
        {
            int i = left;
            while (i <= right)
            {
                ans.push_back(arr[top][i]);
                i++;
            }
            top++;
            pos++;
        }
        else if (pos == 2)
        {
            int i = top;
            while (i <= down)
            {
                ans.push_back(arr[i][right]);
                i++;
            }
            right--;
            pos++;
        }
        else if (pos == 3)
        {
            int j = right;
            while (j >= left)
            {
                ans.push_back(arr[down][j]);
                j--;
            }
            pos++;
            down--;
        }
        else if (pos == 4)
        {
            int j = down;
            while (j >= top)
            {
                ans.push_back(arr[j][left]);
                j--;
            }
            pos /= 4;
            left++;
        }
    }
    return ans;
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
    vector<int> ans=spiralOrder(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}