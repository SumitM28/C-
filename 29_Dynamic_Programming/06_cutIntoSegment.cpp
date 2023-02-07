// Cut Into Segments
#include <bits/stdc++.h>
using namespace std;

// using recursion
int solve(int n, int x, int y, int z)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }

    int a = solve(n - x, x, y, z) + 1;
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;

    return max(a, max(b, c));
}

// using DP appraoch 1st
// recursion + memoization
int solveDp1(int n, int x, int y, int z, vector<int> &dp)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int a = solveDp1(n - x, x, y, z, dp) + 1;
    int b = solveDp1(n - y, x, y, z, dp) + 1;
    int c = solveDp1(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

// using DP approach 2nd
// tabulation
int solveDp2(int n, int x, int y, int z)
{

    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {		
		
		if(i-x>=0)
        	dp[i]= max(dp[i],dp[i-x]+1);
		if(i-y>=0)
        	dp[i]= max(dp[i],dp[i-y]+1);
		if(i-z>=0)
        	dp[i]= max(dp[i],dp[i-z]+1);

       
    }

	if(dp[n] != INT_MIN){
		return dp[n];
	}else{
		return 0;
	}
}

int cutSegments(int n, int x, int y, int z)
{

    // using recursion
    int ans = solve(n, x, y, z);

    // using dp approach 1st
    vector<int> dp(n + 1, -1);
    // ans = solveDp1(n, x, y, z);

    // using dp approach 2nd
    int ans = solveDp2(n, x, y, z);

    if (ans < 0)
    {
        return 0;
    }
    else
    {
        return ans;
    }
}