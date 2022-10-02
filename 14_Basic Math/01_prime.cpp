// program of prime number.

#include <iostream>
#include <vector>
using namespace std;

// brute force.
// check is prime or not.
bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    if (num == 2)
    {
        return true;
    }
    for (int i = 2; i < num - 1; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

// optime sieve of eratosthenes.
vector<int> seiveOfEratosthenes(int num)
{
    vector<int> prime(num , true);
    vector<int> ans;
    prime[0] = prime[1] = false;

    for (int i = 2; i*i < num; i++)
    {
        for(int j=i*i;j<num;j+=i){
            prime[j]=false;
        }
    }
    for(int i=0;i<=prime.size();i++){
        if(prime[i]==true){
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{

    int num;
    cout << "Enter the number:";
    cin >> num;

    // cout<<isPrime(num);

    // for(int i=1;i<=num;i++){
    //     if(isPrime(i)){
    //         cout<<i<<" ";
    //     }
    // }

    vector<int> ans = seiveOfEratosthenes(num);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}