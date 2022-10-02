/*
Gievn an array of interger number.where arr[i] represent the number of pages in the ith book. there are m no of student and the task is to allocate all the book to thier student. allocate books in such way that:
1. each student get at leadt one book.
2. each book should be allocated to a student.
3. book allocation should be in contiguous manner.

you have to allocate the book to m student such that the maximum number of pages assign to a student is minimum.
*/

#include<iostream>
using namespace std;


// check the mid is possible solution or not.
bool checkPossibleSol(int arr[],int n,int m,int mid){
    int studentCount=1;
    int pageSum=0;

    for (int i = 0; i < n; i++)
    {
        if((pageSum+arr[i])<=mid){
            pageSum+=arr[i];
        }else{
            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            pageSum=0;
            pageSum+=arr[i];
        }
    }
    return true;
}
int main(){

    // the array which ith element present no of pages.
    int arr[5]={10,20,30,40};
    int m=2;
    int n=4;

    int s=0;
    int sum=0;

    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }

    int e=sum;

    int mid=s+(e-s)/2;

    int ans=-1;
    while (s<=e)
    {
        

        if(checkPossibleSol(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;

    }
    
    cout<<ans;
    
}