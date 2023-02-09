// Largest square formed in a matrix
#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, int n, int m, vector<vector<int>> &mat, int &maxi)
{
    // base case
    if (i >= n || j >= m)
    {
        return 0;
    }

    int right = solve(i, j + 1, n, m, mat, maxi);
    int diogonal = solve(i + 1, j + 1, n, m, mat, maxi);
    int bottom = solve(i + 1, j, n, m, mat, maxi);

    if (mat[i][j] == 1)
    {
        int ans = 1 + min(right, min(diogonal, bottom));
        maxi = max(ans, maxi);
        return ans;
    }
    else
    {
        return 0;
    }
}

// using rec + memoization
// dp approach 1st
int solveMem(int i, int j, int n, int m, vector<vector<int>> &mat, int &maxi, vector<vector<int>> &dp)
{
    // base case
    if (i >= n || j >= m)
    {
        return 0;
    }

    // check is ans is already present or not
    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solveMem(i, j + 1, n, m, mat, maxi, dp);
    int diogonal = solveMem(i + 1, j + 1, n, m, mat, maxi, dp);
    int bottom = solveMem(i + 1, j, n, m, mat, maxi, dp);

    if (mat[i][j] == 1)
    {
        int ans = 1 + min(right, min(diogonal, bottom));
        maxi = max(ans, maxi);
        return dp[i][j] = ans;
    }
    else
    {
        return dp[i][j] = 0;
    }
}

// using tabulation
// dp approach 2nd
int solveTab(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxi = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            int right = dp[i][j + 1];
            int diogonal = dp[i + 1][j + 1];
            int bottom = dp[i + 1][j];

            if (mat[i][j] == 1)
            {
                int ans = 1 + min(right, min(diogonal, bottom));
                maxi = max(ans, maxi);
                dp[i][j] = ans;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxi;
}

// space optimization
int solveSpaceOptimization(int n, int m, vector<vector<int>> &mat)
{
    vector<int> curr(m+1,0);
    vector<int> next(m+1,0);
    int maxi = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            int right = curr[j + 1];
            int diogonal = next[j + 1];
            int bottom = next[j];

            if (mat[i][j] == 1)
            {
                int ans = 1 + min(right, min(diogonal, bottom));
                maxi = max(ans, maxi);
                curr[j] = ans;
            }
            else
            {
                curr[j] = 0;
            }
        }
        next=curr;
    }
    return maxi;
}

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int maxi = 0;

    // using recursion
    // solve(0, 0, n, m, mat, maxi);

    // using dp approach 1st
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // solveMem(0, 0, n, m, mat, maxi, dp);
    // return maxi;

    // using dp approach 2nd
    return solveTab(n, m, mat);
}

int main(){
    
}