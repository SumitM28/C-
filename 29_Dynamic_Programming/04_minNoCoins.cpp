// Minimum Elements.

#include <bits/stdc++.h>
using namespace std;

// using recursion
int solveRec(vector<int> &num, int x)
{
    // base case
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    int ans = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int temp = solveRec(num, x - num[i]);
        if (temp != INT_MAX)
        {
            ans = min(ans, 1 + temp);
        }
    }
    return ans;
}

// using Dp (top bottom) approach
// recursion and code memoization
int solveDp1(vector<int> &num, int x, vector<int> &dp)
{
    // base case
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    if (dp[x] != -1)
    {
        return dp[x];
    }

    int ans = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int temp = solveDp1(num, x - num[i], dp);
        if (temp != INT_MAX)
        {
            ans = min(ans, 1 + temp);
        }
    }
    dp[x] = ans;
    return ans;
}

// using Dp (bottom top) approach
// tebulation method
int solveDp2(vector<int> &num, int x)
{
    vector<int>  dp(x+1,INT_MAX);
    dp[0]=0;

    for(int i=0;i<=x;i++){
        for(int j=0;j<num.size();j++){
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX)
                dp[i]=min(dp[i], 1 + dp[i-num[j]]); 
        }
    }
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();

    // usign recursion
    // int ans= solveRec(num,x);
    // if(ans == INT_MAX){
    //     return -1;
    // }else{
    //     return ans;
    // }

    // using Dp
    // vector<int> dp(x + 1, -1);
    // int ans = solveDp1(num, x, dp);
    // if (ans == INT_MAX)
    // {
    //     return -1;
    // }
    // else
    // {
    //     return ans;
    // }

    // using tabulation
    int ans = solveDp2(num, x);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(5);
    int x=11;

    cout<<minimumElements(num,x);
}