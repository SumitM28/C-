#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// next smaller element function
vector<int> nextSmallerElement(vector<int> arr, int n)
{

    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top()!=-1 && arr[st.top()]>=curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// previous smaller element fucntion
vector<int> prevSmallerElement(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i =0; i<n; i++)
    {
        int curr = arr[i];
        while (st.top()!=-1 && arr[st.top()]>=curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangular(vector<int> arr, int n)
{
    
    vector<int> next(n);
    next = nextSmallerElement(arr, n);
    
    vector<int> prev(n);
    prev = prevSmallerElement(arr, n);

    int area =-1;

    for (int i = 0; i < n; i++)
    {
        
        int l = arr[i];                // length

        if(next[i]==-1){
            next[i]=n;
        }
        int b = next[i] - prev[i] - 1; // breadth

        
        int newArea = l * b;

        area = max(area, newArea);
    }
    
    return area;
}

int main()
{

    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);

    int area = largestRectangular(arr, arr.size());
    cout << area << endl;
}