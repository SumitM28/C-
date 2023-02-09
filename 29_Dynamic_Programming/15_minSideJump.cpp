// minimum sidebase jump
#include <bits/stdc++.h>
using namespace std;

// using recursion
int solve(vector<int> &obstacles, int currlane, int currpos)
{
    // base case
    if (currpos == obstacles.size() - 1)
        return 0;

    if (obstacles[currpos + 1] != currlane)
    {
        return solve(obstacles, currlane, currpos + 1);
    }
    else
    {

        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currlane != i && obstacles[currpos] != i)
            {
                ans = min(ans, 1 + solve(obstacles, i, currpos));
            }
        }
        return ans;
    }
}

// using dp approach 1st
// recursion + memoization
int solveMem(vector<int> &obstacles, int currlane, int currpos, vector<vector<int>> &dp)
{
    // base case
    if (currpos == obstacles.size() - 1)
        return 0;

    if (dp[currlane][currpos] != -1)
        return dp[currlane][currpos];
    if (obstacles[currpos + 1] != currlane)
    {
        return solveMem(obstacles, currlane, currpos + 1, dp);
    }
    else
    {

        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currlane != i && obstacles[currpos] != i)
            {
                ans = min(ans, 1 + solveMem(obstacles, i, currpos, dp));
            }
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
}

// using dp approach 2nd
// tabulation



int minSideJumps(vector<int> &obstacles)
{
    int n = obstacles.size();
    // using recursion
    return solve(obstacles, 2, 0);

    // using dp approach 1st
    vector<vector<int>> dp(4, vector<int>(n, -1));
    return solveMem(obstacles, 2, 0, dp);

    // using dp approach 2nd
}

int main(){

}