// find the kth largest sum of the subarray.
#include <bits/stdc++.h>
using namespace std;

// approach 1
int kthLargestSum(vector<int> arr, int k)
{

    vector<int> sumStore;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(), sumStore.end());
    return sumStore[sumStore.size() - k];
}

// approach 2
int kthLargestSum(vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (minHeap.size() < k)
            {
                minHeap.push(sum);
            }
            else
            {
                if (minHeap.top() < sum)
                {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    return minHeap.top();
}

int main()
{
    // 5 4 -8 6 -1
    vector<int> arr;
    int k = 10;
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    while (data != -1)
    {
        arr.push_back(data);
        cin >> data;
    }

    int ans = kthLargestSum(arr, k);
    cout << ans;
}