// Combination Sum
#include <bits/stdc++.h>
using namespace std;

// using recursion
int solve(vector<int> &num, int tar)
{
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans = ans + solve(num, tar - num[i]);
    }
    return ans;
}

// using dp approach 1st
// recursion + memoization
int solveDP1(vector<int> &num, int tar, vector<int> &dp)
{
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;
    if (dp[tar] != -1)
        return dp[tar];
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solveDP1(num, tar - num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

// using dp approach 2nd
// tabulation
int solveDP2(vector<int> &num, int tar)
{
    vector<int> dp(tar+1,0);
    dp[0]=1;
    for(int i=1;i<=tar;i++){
     
        for(int j=0;j<num.size();j++){
            if(i-num[j] >=0)
                dp[i]+=dp[i-num[j]];
        }
        
    }
    return dp[tar];
}



int findWays(vector<int> &num, int tar)
{
    return solve(num, tar);

    // using dp approach 1st
    vector<int> dp(tar + 1, -1);
    return solveDP1(num, tar, dp);
}

int main(){
    
}