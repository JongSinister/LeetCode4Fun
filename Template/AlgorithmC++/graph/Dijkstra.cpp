#include <bits/stdc++.h>
using namespace std;
vector<int> Dijkstra(vector<vector<pair<int,int>>> &g,int s){
    int n=g.size();
    vector<int> dist(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        auto &[T,u] = pq.top();
        pq.pop();

        if(T>dist[u]) continue;

        for(auto &[b,w]:g[u]){
            if(dist[b]>dist[u]+w){
                dist[b]=dist[u]+w;
                pq.push({dist[b],b});
            }
        }
    }
    return dist;
}
int main(){
    int N,E,s,a,b,c;
    cin>>N>>E>>s;
    vector<vector<pair<int,int>>> g(N);
    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    for(auto &x:Dijkstra(g,s)){
        cout<<x<<" ";
    }
}