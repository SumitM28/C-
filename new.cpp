#include<bits/stdc++.h>
using namespace std;

bool checkNumber(int num){

    if(num==0 || num==1){
        return false;
    }

    int ones=0;
    int zeros=0;

    while (num)
    {
        int lastDigit=num%10;
        if(lastDigit==1){
            ones++;
        }else{
            zeros++;
        }
        num=num/10;
    }
    
    if(ones==1){
        // cout<<ones<<" "<<zeros<<endl;
        return true;
    }else if(zeros==1){
        return true;
    }
    else{
        false;
    }
}


int main(){

    int t;
    cin>>t;

    while (t--)
    {
        int num;
        cin>>num;

        bool ans= checkNumber(num);
        if(ans==true){
            cout<<"Yes";
        }else{
            cout<<"No";
        }

    }
    

}