#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
    int u,v,w;
};
bool compareEdges(Edge a,Edge b){return a.w<b.w;}
struct DSU{
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int x,int y){
        int rx=find(x),ry=find(y);
        if(rx!=ry){
            if(rank[rx]<rank[ry])
                parent[rx]=ry;
            else if(rank[rx]>rank[ry])
                parent[ry]=rx;
            else{
                parent[ry]=rx;
                rank[rx]++;
            }
        }
    }
};
void kruskal(int n,vector<Edge>&edges){
    sort(edges.begin(),edges.end(),compareEdges);
    DSU dsu(n);
    int mstWeight=0;
    for(int i=0;i<edges.size();i++){
        Edge e=edges[i];
        if(dsu.find(e.u)!=dsu.find(e.v)){
            dsu.unite(e.u,e.v);
            mstWeight+=e.w;
            cout<<e.u<<" - "<<e.v<<" : "<<e.w<<endl;
        }
    }
    cout<<"MST Weight = "<<mstWeight<<endl;
}
int main(){
    int n=4;
    vector<Edge>edges;
    Edge e1;e1.u=0;e1.v=1;e1.w=10;edges.push_back(e1);
    Edge e2;e2.u=0;e2.v=2;e2.w=6;edges.push_back(e2);
    Edge e3;e3.u=0;e3.v=3;e3.w=5;edges.push_back(e3);
    Edge e4;e4.u=1;e4.v=3;e4.w=15;edges.push_back(e4);
    Edge e5;e5.u=2;e5.v=3;e5.w=4;edges.push_back(e5);
    kruskal(n,edges);
}