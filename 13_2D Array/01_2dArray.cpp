// implementation of the 2D array.

#include<iostream>
using namespace std;


int main(){
    // intialize the 2d array.

    // initialization no.1
    // int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};

    // initialization no.2
    // int arr[2][2]={ {1,1},
    //                 {2,2}};

    // initialization no.3
    int arr[3][3];

    // for taking input row wise just change the i and j like arr[j][i];
    // taking input.
    cout<<"Insert the element insise the array:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
   
    // printing the output.
    cout<<"The array is :"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}