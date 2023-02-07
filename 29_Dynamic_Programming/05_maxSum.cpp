// maximum sum of non adjacent element
#include<bits/stdc++.h>
using namespace std;

// using recursion
int solveRec(vector<int> &nums,int n){
    // base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    // include the num
    int includeAns= solveRec(nums,n-2)+nums[n]; 
    // exclude
    int excludeAns=solveRec(nums,n-1);

    return max(includeAns,excludeAns);
}

// using dp approach 1st
// recursion + memoization
int solveDp1(vector<int> &nums,int n,vector<int> &dp){
    // base case
    if(n<0) return 0;

    if(n==0){
        return nums[0];
    }

    if(dp[n] != -1){
        return dp[n];
    }
    // exclude
    int excludeAns=solveDp1(nums,n-1,dp);

    // include the num
    int includeAns= solveDp1(nums,n-2,dp)+nums[n];

    return dp[n]= max(includeAns,excludeAns);
}

// using dp Approach 2nd
// tabulation
int solveDp2(vector<int> &nums,int n){
    // create dp arr
    vector<int> dp(n+1,0);
    dp[0]=nums[0];

    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }

    return dp[n];
}

// space utilization
int solveOptimize(vector<int> &nums,int n){
    // create dp arr
    int prev2=0;
    int prev1=nums[0];

    for(int i=1;i<=n;i++){
        int ans = max(prev1,prev2+nums[i]);
        prev2=prev1;
        prev1=ans;
    }

    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    

    int n=nums.size();

    // usign rescursion
    // return solveRec(nums,n-1);


    // usign dp appraoach 1st
    // vector<int> dp(n,-1);
    // return solveDp1(nums,n-1,dp);


    // usign dp appraoach 2nd
    // return solveDp2(nums,n-1);

    // space optimization
     return solveOptimize(nums,n-1);
}
int main(){

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(4);

    cout<<maximumNonAdjacentSum(nums);

}