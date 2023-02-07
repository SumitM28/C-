// count Derangment
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// usign recursion
long long int countDerangements(int n)
{
    // base case
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    long long int ans = ((n - 1) % MOD) * ((countDerangements(n - 1) % MOD) + (countDerangements(n - 2) % MOD)) % MOD;
    return ans;
}

// using DP approach 1st
// recursion + memoization
long long int solveDp1(int n, vector<long long int> &dp)
{
    // base case
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    // check if ans is already present in dp array
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = ((n - 1) % MOD) * ((solveDp1(n - 1, dp) % MOD) + (solveDp1(n - 2, dp) % MOD)) % MOD;
    return dp[n];
}

// using DP approach 2nd
// Tabulation
long long int solveDp2(int n)
{
    vector<long long int> dp(n + 1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {   
        long long int first= dp[i-1]%MOD;
        long long int second= dp[i-2]%MOD;
        long long int sum= (first+second)%MOD;
        long long int ans= ((i-1)*sum)%MOD;
        dp[i] = ans;
    }

    return dp[n];
}


// space utilization
long long int solveOptimize(int n)
{
    long long int prev2=0;
    long long int prev1=1;

    for (int i = 3; i <= n; i++)
    {   
        long long int first= prev1%MOD;
        long long int second= prev2%MOD;
        long long int sum= (first+second)%MOD;
        long long int ans= ((i-1)*sum)%MOD;
        prev2=prev1;
        prev1=ans;
    }

    return prev1;;
}

int main()
{
    int n = 4;
    // using recursion
    // long long int ans= countDerangements(n);

    // using dp appaoch 1st
    // vector<long long int> dp(n + 1, -1);
    // long long int ans = solveDp1(n, dp);

    // using Dp approach 2nd
    // long long int ans = solveDp2(n);

    // space utilization
    long long int ans = solveOptimize(n);

    cout << ans;
}