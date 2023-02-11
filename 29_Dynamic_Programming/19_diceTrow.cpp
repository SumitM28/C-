// Dice throw
#include <bits/stdc++.h>
using namespace std;

// using recursion
long long solve(int dice, int faces, int target)
{

    // base case
    if (target < 0 || (dice == 0 && target != 0) || (dice != 0 && target == 0))
    {
        return 0;
    }
    if (dice == 0 || target == 0)
        return 1;

    long long ans = 0;

    for (int i = 1; i <= faces; i++)
    {
        ans += solve(dice - 1, faces, target - i);
    }

    return ans;
}

// using dp approach 1st
long long solveTab(int dice, int faces, int target)
{

    // base case
    if (target < 0 || (dice == 0 && target != 0) || (dice != 0 && target == 0))
    {
        return 0;
    }
    if (dice == 0 || target == 0)
        return 1;

    int ans = 0;

    for (int i = 1; i <= faces; i++)
    {
        ans += solveMem(dice - 1, faces, target - i);
    }

    return ans;
}

// using memoization
long long solveMem(int dice, int faces, int target, vector<vector<long long>> &dp)
{

    // base case
    if (target < 0)
    {
        return 0;
    }
    if (dice == 0 && target != 0)
    {
        return 0;
    }
    if (target == 0 && dice != 0)
    {
        return 0;
    }
    if (dice == 0 || target == 0)
        return 1;

    if (dp[dice][target] != -1)
        return dp[dice][target];

    long long ans = 0;

    for (int i = 1; i <= faces; i++)
    {
        ans += solveMem(dice - 1, faces, target - i, dp);
    }

    return dp[dice][target] = ans;
}

// using tabulation
long long funtab(int d, int f, int t)
{

    vector<vector<long long>> dp(d + 1, vector<long long>(t + 1, 0));

    dp[0][0] = 1;

    for (int dice = 1; dice <= d; dice++)
    {

        for (int target = 1; target <= t; target++)
        {

            long long ans = 0;

            for (int i = 1; i <= f; i++)
            {

                if (target - i >= 0)
                    ans += dp[dice - 1][target - i];
            }

            dp[dice][target] = ans;
        }
    }

    return dp[d][t];
}
// using optimization
long long solveSpaceOptimize(int d, int f, int t)
{

    vector<long long > prev(t+1,0);
    vector<long,long>  curr(t+1);

    prev[0] = 1;

    for (int dice = 1; dice <= d; dice++)
    {

        for (int target = 1; target <= t; target++)
        {

            long long ans = 0;

            for (int i = 1; i <= f; i++)
            {

                if (target - i >= 0)
                    ans += prev[target - i];
            }

            curr[target] = ans;
        }
        prev=curr;
    }

    return curr[t];
}
long long noOfWays(int M, int N, int X)
{
    // using recursion
    // return solve(N, M, X);

    // memoization
    vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, -1));
    return solveMem(N, M, X, dp);
}