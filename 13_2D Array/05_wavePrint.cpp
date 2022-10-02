// print in the wave form.

#include <iostream>
using namespace std;

// print in waveform.

void print(int arr[][3], int n, int m)
{

   int left=0;
   int right=m-1;

   int position=1;
    while (left<=right)
    {
        if (position==1)
        {
            int i=0;
            while (i<n)
            {
                cout<<arr[i][left]<<" ";
                i++;
            }
            position++;
        }else{
            int j=n-1;
            while (j>=0)
            {
                cout<<arr[j][left]<<" ";
                j--;
            }
            position=position/2;
        }
        left++;
    }
    
    
}
int main()
{

    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    print(arr, 3, 3);
}