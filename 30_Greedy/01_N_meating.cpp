// N meating in one room
#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back({start[i], end[i]});
    }

    sort(ans.begin(), ans.end(), cmp);
    int count = 1;
    int ansEnd = ans[0].second;

    for (int i = 1; i < n; i++)
    {
        if (ans[i].first > ansEnd)
        {
            count++;
            ansEnd = ans[i].second;
        }
    }

    return count;
}

int main(){
    
}