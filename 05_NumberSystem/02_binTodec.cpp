// program to convert the binary to decimal.
#include <math.h>
#include <iostream>
using namespace std;

int main()
{

   int n;
   cout<<"Enter the number:";
   cin>>n;

   int  i=0,ans=0;

   while (n!=0)
   {
        int digit=n%10;

        if(digit==1){
            ans=ans+pow(2,i);
        }

        n=n/10;
        i++;
   }
   

   cout<<ans;
}