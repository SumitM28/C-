// Max rectangle
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// next smaller element function
vector<int> nextSmallerElement(int arr[], int n)
{

    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// previous smaller element fucntion
vector<int> prevSmallerElement(int arr[], int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangular(int arr[], int n)
{

    vector<int> next(n);
    next = nextSmallerElement(arr, n);

    vector<int> prev(n);
    prev = prevSmallerElement(arr, n);

    int area = -1;

    for (int i = 0; i < n; i++)
    {

        int l = arr[i]; // length

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1; // breadth

        int newArea = l * b;

        area = max(area, newArea);
    }

    return area;
}

int maxArea(int *M, int n, int m)
{
    // Your code here
    int area = largestRectangular(M[0], m);

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
        }

        area = max(area, largestRectangular(M[i], m));
    }
    return area;
}

int main()
{
    int n = 4, m = 4;
    int arr[n][m] = { {0,1,1,0},
                      {1,1,1,1},
                      {1,1,1,1},
                      {1,1,0,0} };
    
    // for(int i=0;i<n;i++){
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<maxArea(arr,n,m);
}