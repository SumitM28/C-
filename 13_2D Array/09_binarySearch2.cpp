// find a element in the array which is row wise as well as column wise sorted.
#include <iostream>
#include <vector>
using namespace std;

// binary search
bool binarySearch(vector<vector<int>> arr, int key)
{

    int row = arr.size();
    int col = arr[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0)
    {
        int element = arr[rowIndex][colIndex];
        if (element == key)
        {
            return true;
        }
        else if (element < key)
        {
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
    }
    return false;
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
    };

    int key;
    cout << "Element to be search:";
    cin >> key;
    bool ans = binarySearch(arr, key);
    if (ans)
    {
        cout << "Element is found.";
    }
    else
    {
        cout << "Element is not found.";
    }
}