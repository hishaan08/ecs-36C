#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bucketSort(float arr[],int n){
    vector<float>b[n];
    for(int i=0;i<n;i++){
        int bi=n*arr[i];
        b[bi].push_back(arr[i]);
    }
    for(int i=0;i<n;i++)
        sort(b[i].begin(),b[i].end());
    int idx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<b[i].size();j++)
            arr[idx++]=b[i][j];
    }
}
int main(){
    float arr[]={0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
    int n=10;
    bucketSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}