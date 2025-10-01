#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void topoUtil(int u,vector<vector<int> >&adj,vector<bool>&vis,stack<int>&st){
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!vis[v])
            topoUtil(v,adj,vis,st);
    }
    st.push(u);
}
int main(){
    int n=6;
    vector<vector<int> >adj(n);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);
    vector<bool>vis(n,false);
    stack<int>st;
    for(int i=0;i<n;i++)
        if(!vis[i])
            topoUtil(i,adj,vis,st);
    cout<<"Topological Sort: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}