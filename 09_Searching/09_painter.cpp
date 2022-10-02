/*
given an array of length n , where the array represents the boards and each element of the given array represent the length of each board. some k numbers of painters are available to  paint these boards. consider the each unit of a board takes 1 unit of time to paint.
*/

#include <iostream>
using namespace std;

bool isPossible(int boards[], int n, int k, int mid)
{

    int boardCount = 1;
    int boardSum = 0;

    for (int i = 0; i < n; i++)
    {

        if (boardSum + boards[i] <= mid)
        {
            boardSum += boards[i];
        }
        else
        {
            boardCount++;
            if (boardCount > k || boards[i] > mid)
            {
                return false;
            }
            boardSum = 0;
            boardSum += boards[i];
        }
    }
    return true;
}

int main()
{
    int boards[4]={10,20,30,40};
    int s = 0;
    int sum = 0;
    int n = 4;
    int k=2;
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
    }
    int e = sum;

    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {

        if (isPossible(boards, n, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    cout<< ans;
}