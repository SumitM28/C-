// how can be terminate the infinite loop while switch case in present in the loop ans we can not use the break;

#include <iostream>
using namespace std;

int main()
{

    int n = 1;

    while (n > 0)
    {
        switch (n)
        {
        case 100:
            cout << "Now at the 100 we can terminate the infinite loop without using any break statement --)" << endl;
            exit(1);
        }
        n++;
    };
}