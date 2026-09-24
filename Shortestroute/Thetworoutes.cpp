
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>track;
vector<vector<int>>road;
vector<vector<bool>>istrack;
void bfs(int node,vector<int>&dist,vector<vector<int>>&adj){
    priority_queue<pair<int,int>>pq;
    pq.push({node,0});
    dist[node]=0;
    while(!pq.empty()){
        int curr=pq.top().first;
        int cst=pq.top().second;
        pq.pop();
        for(auto i:adj[curr]){
            if(dist[i]>dist[curr]+1){
                dist[i]=dist[curr]+1;
                pq.push({i,dist[i]});
            }
        }
    }
}
signed main(){
    int n,m;
    cin>>n>>m;
    track.resize(n);
    road.resize(n);
    istrack.assign(n,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        track[u].push_back(v);
        track[v].push_back(u);
        istrack[u][v]=true;
        istrack[v][u]=true;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!istrack[i][j]){
                road[i].push_back(j);
                road[j].push_back(i);
            }
        }
    }
    vector<int>traindist(n,LLONG_MAX);
    vector<int>busdist(n,LLONG_MAX);
    bfs(0,traindist,track);
    bfs(0,busdist,road);
    if(traindist[n-1]!=LLONG_MAX&&busdist[n-1]!=LLONG_MAX){
        cout<<max(traindist[n-1],busdist[n-1])<<endl;
    }else{
        cout<<-1<<endl;
    }
}