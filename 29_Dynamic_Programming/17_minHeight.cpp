// Minimum height by stacking cuboid.
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &a, vector<int> &b)
{

    if (b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}
int solveSpaceOptimize(int n, vector<vector<int>> &a)
{

    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || check(a[curr], a[prev]))
            {
                include = a[curr][2] + nextRow[curr + 1];
            }

            int exclude = 0 + nextRow[prev + 1];
            currRow[prev + 1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}
int maxHeight(vector<vector<int>> &cuboids)
{
    // sort all the diamentsion
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }

    // sort all cuboids
    sort(cuboids.begin(), cuboids.end());

    // put the algo largest increasing subsequence
    return solveSpaceOptimize(cuboids.size(), cuboids);
}

int main(){

}