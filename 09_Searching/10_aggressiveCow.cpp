/*
Given an array of length N where each element denotes the position of a stall.Now you have N stalls and an integer k which denoted the number of cows that are aggresive. to prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. return the largest minimum distance.
*/

#include <iostream>
using namespace std;

//  to check is possible
bool isPossible(int stalls[], int n,int k,int mid){
    int cowCount=1;
    int lastPos=stalls[0];
    
    for(int i=0;i<n;i++){
        if(stalls[i]-lastPos>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastPos=stalls[i];
        }
    }
    return false;
}

int main()
{
    int stalls[5] = {4, 2, 1, 3, 6};
    int k = 2;
    int n = 5;

    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {

        if (maxi < stalls[i])
        {
            maxi = stalls[i];
        }
    }
    int e = maxi;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(stalls,n, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    cout<< ans;
}