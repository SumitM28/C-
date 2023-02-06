// Count ways to reach Nth Stair.
#include <bits/stdc++.h>
using namespace std;
int countDistinctWays(int nStairs, int curr)
{
    //  base case
    if (nStairs == curr)
    {
        return 1;
    }
    if (curr > nStairs)
    {
        return 0;
    }

    return countDistinctWays(nStairs, curr + 1) + countDistinctWays(nStairs, curr + 2);
}

int main()
{

    int nStairs = 3;
    cout<<countDistinctWays(nStairs,0);
}