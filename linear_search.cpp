#include<iostream>
using namespace std;
int linearSearch(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x) return i;
    }
    return -1;
}
int main(){
    int arr[]={2,4,6,8,10};
    int n=5,x=8;
    int idx=linearSearch(arr,n,x);
    cout<<"Index: "<<idx<<endl;
}
