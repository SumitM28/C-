// print the total prime number upto n

#include <iostream>
using namespace std;
bool checkPrime(int n){

    if(n==0 || n==1){
        return false;
    }

    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main()
{

    int n;
    cout << "Enter the range:";
    cin >> n;

    for(int i=1;i<n;i++){

        if(checkPrime(i)){
            cout<<i<<endl;
        }
    }
    
    
}

