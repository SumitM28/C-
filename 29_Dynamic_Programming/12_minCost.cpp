// min cost to travel
#include <bits/stdc++.h>
using namespace std;

// using recursion
int solve(int n, vector<int> &days, vector<int> &cost, int i)
{

    // base case
    if (i >= n)
    {
        return 0;
    }

    // 1 day pass
    int option1 = cost[0] + solve(n, days, cost, i + 1);

    int idx;
    // 7 day pass
    for (idx = i; idx < n && days[idx] < days[i] + 7; idx++)
        ;
    int option2 = cost[1] + solve(n, days, cost, idx);

    // 30 day pass
    for (idx = i; idx < n && days[idx] < days[i] + 30; idx++)
        ;
    int option3 = cost[2] + solve(n, days, cost, idx);

    return min(option1, min(option2, option3));
}

// using dp appraoch 1st
// recursion + memoization
int solveMem(int n, vector<int> &days, vector<int> &cost, int i, vector<int> &dp)
{

    // base case
    if (i >= n)
    {
        return 0;
    }
    // check if ans is already present in dp arr
    if (dp[i] != -1)
        return dp[i];

    // 1 day pass
    int option1 = cost[0] + solveMem(n, days, cost, i + 1, dp);

    int idx;
    // 7 day pass
    for (idx = i; idx < n && days[idx] < days[i] + 7; idx++)
        ;
    int option2 = cost[1] + solveMem(n, days, cost, idx, dp);

    // 30 day pass
    for (idx = i; idx < n && days[idx] < days[i] + 30; idx++)
        ;
    int option3 = cost[2] + solveMem(n, days, cost, idx, dp);

    dp[i] = min(option1, min(option2, option3));
    return dp[i];
}

// using dp appraoch 2nd
// tabulation
int solveTab(int n, vector<int> &days, vector<int> &cost)
{

    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int option1 = cost[0] + dp[i + 1];

        int idx;
        // 7 day pass
        for (idx = i; idx < n && days[idx] < days[i] + 7; idx++)
            ;
        int option2 = cost[1] + dp[idx];
        // 30 day pass
        for (idx = i; idx < n && days[idx] < days[i] + 30; idx++)
            ;
        int option3 = cost[2] + dp[idx];

        dp[i] = min(option1, min(option2, option3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // using recursion
    // return solve(n,days,cost,0);

    // using dp appraoch 1st
    // vector<int> dp(n+1, -1);
    // return solveMem(n, days, cost, 0, dp);

    // using dp appraoch 2nd
    // return solveTab(n,days,cost);
}

int main()
{

    return 0;
}