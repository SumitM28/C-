// min score Triangular
#include <bits/stdc++.h>
using namespace std;

// usign recursion

int solve(vector<int> &v, int i, int j)
{
    // base case
    if (i + 1 == j)
    {
        return 0;
    }
    int ans = INT_MAX;

    for (int k = i + 1; k <= j - 1; k++)
    {
        ans = min(ans, v[i] * v[j] * v[k] + solve(v, i, k) + solve(v, k, j));
    }

    return ans;
}

// using recursion + memoization
// Dp approach 1st
int solveMem(vector<int> &v, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i + 1 == j)
    {
        return 0;
    }
    int ans = INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int k = i + 1; k <= j - 1; k++)
    {
        ans = min(ans, v[i] * v[j] * v[k] + solveMem(v, i, k, dp) + solveMem(v, k, j, dp));
    }

    return dp[i][j] = ans;
}

// using tabulation
// Dp approach 2nd
int solveTab(vector<int> &v)
    {
        int n = v.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;
                for (int k = i + 1; k <= j - 1; k++)
                {
                    ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
                }
            
                dp[i][j] = ans;
            }
        }

        return dp[0][n-1];
    }

int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();

    // using recursion
    // return solve(values, 0, n - 1);

    // using dp approach 1st
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return solveMem(values, 0, n - 1, dp);

    // using dp approach 2nd
    return solveTab(values);
}


int main(){

    
}