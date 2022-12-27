#include <iostream>
using namespace std;

class petrolPump
{
public:
    int petrol;
    int distance;
};

int printTour(petrolPump p[], int n)
{

    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit = balance;
            balance = 0;
            start = i + 1;
        }
    }

    if (deficit + balance > 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int main()
{

    petrolPump arr[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);

    (start == -1) ? cout << "No solution" : cout << "Start = " << start;

    return 0;
}