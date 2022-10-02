// pointer and array
#include <iostream>
using namespace std;

int main()
{

    int arr[5] = {5, 1, 2, 7, 40};
    int *ptr = arr;

    cout << "Displaying address using arrays: " << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << "&arr[" << i << "] = " << &arr[i] << endl;
    }

    // ptr = &arr[0]
    // ptr = arr;

    cout << "\nDisplaying address using pointers: " << endl;

    // use for loop to print addresses of all array elements
    // using pointer notation
    for (int i = 0; i < 5; ++i)
    {
        cout << "ptr + " << i << " = " << ptr + i << endl;
    }
}