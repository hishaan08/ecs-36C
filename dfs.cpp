#include<iostream>
#include<vector>
using namespace std;
void dfs(int v,vector<int>adj[],vector<bool>&vis){
    vis[v]=true;
    cout<<v<<" ";
    for(int u:adj[v])
        if(!vis[u])
            dfs(u,adj,vis);
}
int main(){
    int n=4;
    vector<int>adj[4];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);
    vector<bool>vis(n,false);
    dfs(2,adj,vis);
}