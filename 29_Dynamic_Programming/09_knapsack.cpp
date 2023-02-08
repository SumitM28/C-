// Knapsack problem
#include <bits/stdc++.h>
using namespace std;

// using recursion
int solve(vector<int> &weight, vector<int> &value, int i, int capacity)
{

    // base case
    if (i == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;
    // check if the weight of element is should be lie in range of capciy
    if (weight[i] <= capacity)
    {
        include = value[i] + solve(weight, value, i - 1, capacity - weight[i]);
    }
    int exclude = solve(weight, value, i - 1, capacity);

    return max(include, exclude);
}

// using dp approach 1st
// recurstion + memoization
int solveMem(vector<int> &weight, vector<int> &value, int i, int capacity,
             vector<vector<int>> &dp)
{

    // base case
    if (i == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    // check if ans is already present in dp arr
    if (dp[i][capacity] != -1)
    {
        return dp[i][capacity];
    }
    int include = 0;
    // check if the weight of element is should be lie in range of capciy
    if (weight[i] <= capacity)
    {
        include = value[i] + solveMem(weight, value, i - 1, capacity - weight[i], dp);
    }
    int exclude = solveMem(weight, value, i - 1, capacity, dp);

    dp[i][capacity] = max(include, exclude);
    return dp[i][capacity];
}

// using dp approach 2nd
// Tabulation
int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // analyze the base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            // check if the weight of element is should be lie in range of capciy
            if (weight[index] <= w)
            {
                include = value[index] + dp[index-1][w- weight[index]];
            }
            int exclude = dp[index-1][w];

            dp[index][w] = max(include, exclude);
            
        }
    }
    return dp[n-1][capacity];
} 

// space memoization
int solveSpaceOptimize(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // analyze the base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            // check if the weight of element is should be lie in range of capciy
            if (weight[index] <= w)
            {
                include = value[index] + prev[w - weight[index]];
            }
            int exclude = prev[w];

            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[capacity];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    // return solve(weight, value, n - 1, maxWeight);

    // using dp approach 1st
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(weight, value, n - 1, maxWeight, dp);
}

int main()
{
}