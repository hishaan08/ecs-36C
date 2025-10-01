#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
void dijkstra(int n,vector<vector<pii> >&adj,int src){
    vector<int>dist(n,1e9);
    dist[src]=0;
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(d>dist[u])
            continue;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first,w=adj[u][i].second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<"Dist from "<<src<<" to "<<i<<": "<<dist[i]<<endl;
}
int main(){
    int n=5;
    vector<vector<pii> >adj(n);
    adj[0].push_back(make_pair(1,10));
    adj[0].push_back(make_pair(4,5));
    adj[1].push_back(make_pair(2,1));
    adj[1].push_back(make_pair(4,2));
    adj[2].push_back(make_pair(3,4));
    adj[3].push_back(make_pair(0,7));
    adj[3].push_back(make_pair(2,6));
    adj[4].push_back(make_pair(1,3));
    adj[4].push_back(make_pair(2,9));
    adj[4].push_back(make_pair(3,2));
    dijkstra(n,adj,0);
}