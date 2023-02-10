// Pizza With 3n Slices
#include <bits/stdc++.h>
using namespace std;

// using namespce
int solve(int index, int endIdx, vector<int> &slices, int n)
{
    // base case
    if (index > endIdx || n == 0)
        return 0;

    // when take a slice
    int take = slices[index] + solve(index + 2, endIdx, slices, n - 1);
    // not take a slice
    int notTake = 0 + solve(index + 1, endIdx, slices, n);

    return max(take, notTake);
}

// using dp approach 1st
int solveMem(int index, int endIdx, vector<int> &slices, int n, vector<vector<int>> &dp)
{
    // base case
    if (n == 0 || index > endIdx)
    {
        return 0;
    }

    if (dp[index][n] != -1)
    {
        return dp[index][n];
    }

    // when take a slice
    int take = slices[index] + solveMem(index + 2, endIdx, slices, n - 1, dp);
    // not take a slice
    int notTake = 0 + solveMem(index + 1, endIdx, slices, n, dp);

    return dp[index][n] = max(take, notTake);
}

// using dp approach 2nd
int solveTab(vector<int> &slices)
{
    int k = slices.size();
    vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
    vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));
    for (int index = k - 2; index >= 0; index--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slices[index] + dp1[index + 2][n - 1];
            int notTake = 0 + dp1[index + 1][n];
            dp1[index][n] = max(take, notTake);
        }
    }
    int case1 = dp1[0][k / 3];
    for (int index = k - 1; index >= 1; index--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slices[index] + dp2[index + 2][n - 1];
            int notTake = 0 + dp2[index + 1][n];
            dp2[index][n] = max(take, notTake);
        }
    }

    int case2 = dp2[1][k / 3];
    return max(case1, case2);
}

// using space optimize
// space optimisation
int solveSpaceOptimisation(vector<int> &slices)
{
    int k = slices.size();
    vector<int> prev1(k + 2, 0);
    vector<int> curr1(k + 2, 0);
    vector<int> next1(k + 2, 0);

    vector<int> prev2(k + 2, 0);
    vector<int> curr2(k + 2, 0);
    vector<int> next2(k + 2, 0);

    for (int index = k - 2; index >= 0; index--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slices[index] + next1[n - 1];
            int notTake = 0 + curr1[n];
            prev1[n] = max(take, notTake);
        }
        next1 = curr1;
        curr1 = prev1;
    }
    int case1 = curr1[k / 3];
    for (int index = k - 1; index >= 1; index--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slices[index] + next2[n - 1];
            int notTake = 0 + curr2[n];
            prev2[n] = max(take, notTake);
        }
        next2 = curr2;
        curr2 = prev2;
    }

    int case2 = curr2[k / 3];
    return max(case1, case2);
}

int maxSizeSlices(vector<int> &slices)
{
    int k = slices.size();
    // recursion
    // int case1 = solve(0,k-2, slices, k / 3);
    // int case2 = solve(1,k-1, slices, k / 3);

    // using dp approach 1st
    // int k = slices.size();
    // vector<vector<int>> dp(k, vector<int>(k, -1));
    // int case1 = solveMem(0, k - 2, slices, k / 3, dp);
    // vector<vector<int>> dp2(k, vector<int>(k, -1));
    // int case2 = solveMem(1, k - 1, slices, k / 3, dp2);
    // return max(case1, case2);

    /*tabulation
    return solveTab(slices);
    */

    // Space Optimisation
    return solveSpaceOptimisation(slices);
}

int main()
{
}