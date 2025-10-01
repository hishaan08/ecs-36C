#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
void primMST(int n,vector<vector<pii> >&adj){
    vector<int>key(n,1e9),parent(n,-1);
    vector<bool>inMST(n,false);
    key[0]=0;
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        inMST[u]=true;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first,w=adj[u][i].second;
            if(!inMST[v]&&w<key[v]){
                key[v]=w;
                pq.push(make_pair(key[v],v));
                parent[v]=u;
            }
        }
    }
    int total=0;
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<" : "<<key[i]<<endl;
        total+=key[i];
    }
    cout<<"MST Weight = "<<total<<endl;
}
int main(){
    int n=5;
    vector<vector<pii> >adj(n);
    adj[0].push_back(make_pair(1,2));
    adj[0].push_back(make_pair(3,6));
    adj[1].push_back(make_pair(0,2));
    adj[1].push_back(make_pair(2,3));
    adj[1].push_back(make_pair(3,8));
    adj[1].push_back(make_pair(4,5));
    adj[2].push_back(make_pair(1,3));
    adj[2].push_back(make_pair(4,7));
    adj[3].push_back(make_pair(0,6));
    adj[3].push_back(make_pair(1,8));
    adj[4].push_back(make_pair(1,5));
    adj[4].push_back(make_pair(2,7));
    primMST(n,adj);
}