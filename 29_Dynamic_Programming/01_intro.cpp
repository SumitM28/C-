// let's discuss about DP
#include <bits/stdc++.h>
using namespace std;

// top to bottom approach
// recursion and memoization
int fibbonacci(int n, vector<int> &dp)
{
    // base case 
    if (n == 0 || n == 1)
    {
        dp[n] = n;
        return dp[n];
    }

    // check in dp array
    // memoization
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fibbonacci(n - 1, dp) + fibbonacci(n - 2, dp);
    return dp[n];
}


// bottom to top approach
// tabulation method
int fib(int n){
    vector<int> dp(n+1);

    // base case 
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// fibbonacci usign space utlization
int fibOptimize(int n){
    
    int prev1=1;
    int prev2=0;

    for(int i=2;i<=n;i++){
        int curr= prev1 +prev2;

        // shift logic
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main()
{
    int n = 6;
    vector<int> fibboArray(n + 1, -1);
    cout << fibbonacci(n, fibboArray) << endl;
}