#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largetst = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largetst] < arr[left])
    {
        largetst = left;
    }
    if (right < n && arr[largetst] < arr[right])
    {
        largetst = right;
    }

    if (largetst != i)
    {
        swap(arr[largetst], arr[i]);
        heapify(arr, n, largetst);
    }
}

vector<int> mergeHeap(vector<int> a, vector<int> b)
{

    vector<int> ans;
    for (auto i : a)
    {
        ans.push_back(i);
    }
    for (auto i : b)
    {
        ans.push_back(i);
    }
    int size = ans.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(ans, size, i);
    }
    return ans;
}

int main()
{

    vector<int> MH1, MH2;
    MH1.push_back(10);
    MH1.push_back(5);
    MH1.push_back(6);
    MH1.push_back(2);

    MH2.push_back(12);
    MH2.push_back(7);
    MH2.push_back(9);

    vector<int> ans = mergeHeap(MH1, MH2);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}