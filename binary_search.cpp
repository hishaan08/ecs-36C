#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int x){
    int l=0,r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]<x)
            l=mid+1;
        else
            r=mid-1;
    }
    return -1;
}
int main(){
    int arr[]={1,3,5,7,9};
    int n=5,x=7;
    int idx=binarySearch(arr,n,x);
    cout<<"Index: "<<idx<<endl;
}