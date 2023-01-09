#include <bits/stdc++.h>

using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    // code here

    priority_queue<int> q;

    for (int i = l; i < k; i++)
    {
        q.push(arr[i]);
    }

    for (int i = k; i <= r; i++)
    {
        if (arr[i] < q.top())
        {
            q.pop();
            q.push(arr[i]);
        }
    }

    return q.top();
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int ans = kthSmallest(arr, 0, 5, k);
    cout << ans;
}