// Min Cost Climbing Stairs
#include <bits/stdc++.h>
using namespace std;

// using recusion
int minCost(vector<int> &cost, int n)
{
    // base case
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }

    return min(minCost(cost, n - 1), minCost(cost, n - 2)) + cost[n];
}

// usign Dp approach 1st
// recursion + memoization
int minCostDp1(vector<int> &cost, int n, vector<int> &dp)
{
    // base case
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }

    // check if the solution is already present in dp array.
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = min(minCostDp1(cost, n - 1, dp), minCostDp1(cost, n - 2, dp)) + cost[n];
}

// usign Dp approach 2nd
// tabulation method
int minCostDp2(vector<int> &cost, int n)
{
    // create dp array
    vector<int> dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i=2;i<n;i++){
        dp[i]=min(dp[i-1], dp[i-2]) + cost[i];
    }
    return min(dp[n-1], dp[n-2]);
}

// space utlization
int minCostSpaceOptimize(vector<int> &cost, int n){
    // create 2 variables
    int prev1=cost[1];
    int prev2=cost[0];

    for(int i=2;i<n;i++){
        int curr= cost[i] + min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }

    return min(prev1,prev2);
}

int main()
{
    vector<int> cost;
    cost.push_back(10);
    cost.push_back(15);
    cost.push_back(20);

    int n = cost.size();

    // using recursion
    // int ans = min(minCost(cost, n - 1), minCost(cost, n - 2));
    // cout << ans;

    // using dp approach 1st
    // vector<int> dp(n + 1, -1);
    // int ans = min(minCostDp1(cost, n - 1, dp), minCostDp1(cost, n - 2, dp));
    // cout<< ans;

    // using dp approach 2nd
    // int ans = minCostDp2(cost,n);
    // cout<< ans;

    // space utilization
    int ans=minCostSpaceOptimize(cost,n);
    cout<<ans;
}