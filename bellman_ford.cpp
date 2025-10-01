#include<iostream>
#include<vector>
using namespace std;
struct Edge{
    int u,v,w;
};
void bellmanFord(int n,vector<Edge>&edges,int src){
    vector<int>dist(n,1e9);
    dist[src]=0;
    for(int i=1;i<=n-1;i++){
        for(int i=0;i<edges.size();i++){
            Edge e=edges[i];
            if(dist[e.u]!=1e9&&dist[e.u]+e.w<dist[e.v]){
                dist[e.v]=dist[e.u]+e.w;
            }
        }
    }
    for(int i=0;i<edges.size();i++){
        Edge e=edges[i];
        if(dist[e.u]!=1e9&&dist[e.u]+e.w<dist[e.v]){
            cout<<"Graph contains negative weight cycle"<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++)
        cout<<"Dist from "<<src<<" to "<<i<<": "<<dist[i]<<endl;
}
int main(){
    int n=5;
    vector<Edge>edges;
    Edge e1;e1.u=0;e1.v=1;e1.w=-1;edges.push_back(e1);
    Edge e2;e2.u=0;e2.v=2;e2.w=4;edges.push_back(e2);
    Edge e3;e3.u=1;e3.v=2;e3.w=3;edges.push_back(e3);
    Edge e4;e4.u=1;e4.v=3;e4.w=2;edges.push_back(e4);
    Edge e5;e5.u=1;e5.v=4;e5.w=2;edges.push_back(e5);
    Edge e6;e6.u=3;e6.v=2;e6.w=5;edges.push_back(e6);
    Edge e7;e7.u=3;e7.v=1;e7.w=1;edges.push_back(e7);
    Edge e8;e8.u=4;e8.v=3;e8.w=-3;edges.push_back(e8);
    bellmanFord(n,edges,0);
}