// find all the power set of the array/string
#include <iostream>
#include <vector>
using namespace std;

void powerSet(vector<int> &nums, int i, vector<int> output, vector<vector<int>> &ans)
{
    if (i >= nums.size())
    {

        ans.push_back(output);
        return;
    }

    // exclude
    powerSet(nums, i + 1, output, ans);

    // include
    int element = nums[i];
    output.push_back(element);
    powerSet(nums, i + 1, output, ans);
}
vector<vector<int>> subsets(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> output;
    int idx = 0;
    powerSet(arr, idx, output, ans);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the input of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> ans = subsets(arr);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){

            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}