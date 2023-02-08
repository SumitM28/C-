// Ninja And The Fence
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int mul(int a, int b) { return ((a % MOD) * 1LL * (b % MOD)) % MOD; }

// usign recursion
int solve(int n, int k)
{
    // base case
    if (n == 1)
    {
        return k;
    }

    if (n == 2)
    {
        return add(k, mul(k, k - 1));
    }

    int first = mul(solve(n - 2, k), k - 1);
    int second = mul(solve(n - 1, k), k - 1);
    int ans = add(first, second);
}

// usign dp approach 1st
// recursion + memoization
int solveDp1(int n, int k, vector<int> &dp)
{
    // base case
    if (n == 1)
    {
        return k;
    }

    if (n == 2)
    {
        return add(k, mul(k, k - 1));
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    int first = mul(solve(n - 2, k), k - 1);
    int second = mul(solve(n - 1, k), k - 1);
    dp[n] = add(first, second);
    return dp[n];
}

// usign dp approach 2nd
// tabulation
int solveDp2(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int first = mul(dp[i-2], k - 1);
        int second = mul(dp[i-1], k - 1);
        dp[i] = add(first, second);
    }
    return dp[n];
}

// using space optimize
int solveOptmise(int n, int k)
{
    
    int prev2 = k;
    int prev1 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int first = mul(prev2, k - 1);
        int second = mul(prev1, k - 1);
        int ans = add(first, second);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int numberOfWays(int n, int k)
{
    // usign recursion
    return solve(n, k);

    // usign Dp Approach 1st
    vector<int> dp(n, -1);
    return solveDp1(n, k, dp);
}

int main(){
    
}