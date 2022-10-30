#include<bits/stdc++.h>
using namespace std;






int compare(int a,int b,int n){

    if (!(n & 1)) {
 
        a = abs(a);
        b = abs(b);
    }

    // cout<<temp1<<" "<<temp2<<endl;
    if(a>b){
        return 1;
    }
    else if( a<b){
        return 2;
    }
    
    else if( a==b){
        return 0;
    }

}
int main(){
    
    int t;
    cin>>t;
    while (t--)
    {
    int a,b,n;
    cin>>a>>b>>n;
    
    int ans= compare(a,b,n);
    cout<<ans;
    }
    
    

}