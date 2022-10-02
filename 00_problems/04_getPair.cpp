// program to get the pair which is equal to the given sum

#include<iostream>
#include<vector>
using namespace std;


int getPair(int arr[],int n, int s){
   
    

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]+arr[j]==s){
                int temp[];
                temp.push_back(min(arr[j],arr[i]));
                temp.push_back(max(arr[j],arr[i]));
                ans.push_back(temp);
            }
        }
        
    }

    sort(ans.begin(),ans.end());
    return ans;
    
}


int main(){

    int n,s;
    cout<<"Enter the size of array :";
    cin>>n1;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the sum:";
    cin>>s;
    
    
    int ans=getPair(arr,n,s);
    int size=sizeof(ans)/sizeof(ans[0]);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    
}