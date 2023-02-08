// prefect square problem
#include<bits/stdc++.h>
using namespace std;


// using recursion
int solve(int n){
    // base case 
    if(n==0) return 0;

    int ans=n;
    for(int i=1;i*i<=n;i++){
        ans=min(ans,solve(n-i*i));
    }

    return ans;
}

// Dp approach 1st 
// recursion + tabulation

int solveMem(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solveMem(n - i * i, dp));
    }
    dp[n] = ans;
    return dp[n];
}


// Dp approach 2nd
// Tabulation

int solveMem(int n)
{

    // create dp array
    vector<int> dp(n+1,0);
    dp[0]=0;
    int ans=n;
    for(int i=1;i*i<=n;i++){
       ans = min(ans, 1 + dp[n-i*i]);
       dp[i]=ans;
    }
    return dp[n];
}

// Dp approach 2nd
// tabulation

int solveTab(int n)
{

    // create dp array
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    
    for(int i=1;i<=n;i++){
       for(int j=1;j*j<=n;j++){
           if(i-j*j >= 0)
                dp[i]=min(dp[i],1+dp[i-j*j]);
       }
    }
    return dp[n];
}

int MinSquares(int n)
{
    // create dp array
    vector<int> dp(n + 1, -1);
    return solveMem(n, dp);
}

int main(){
    
}