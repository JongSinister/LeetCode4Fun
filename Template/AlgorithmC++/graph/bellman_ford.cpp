#include <bits/stdc++.h>
using namespace std;

// SINGLE ARRAY BELLMAN_FORD ALGORITHM
vector<int> bellman_ford(vector<vector<pair<int,int>>> &g,int s){
    int n=g.size();
    vector<int> dist(n,10000);
    dist[s]=0;
    for(int i=1;i<n;i++){
        for(int node=0;node<n;node++){
            for(auto &[b,w]:g[node]){
                dist[node]=min(dist[node],dist[b]+w);
            }
        }
    }
    for(int node=0;node<n;node++){
        for(auto &[b,w]:g[node]){
            if(dist[node]>dist[b]+w){
                return {-1};
            }
        }   
    }
    return dist;
}

// BEFORE-AFTER VERSION
vector<int> bellman_ford_bf_af_ver(map<int,vector<pair<int,int>>> &g,int s){
    vector<int> before(g.size(),1001);
    vector<int> after(g.size(),1001);
    before[s]=0;after[s]=0;
    for(int i=1;i<g.size();i++){
        for(int j=0;j<g.size();j++){
            for(auto &[b,w]:g[j]){
                after[j]=min({after[j],before[b]+w});
            }
        }
        before=after;
    }
    for(int j=0;j<g.size();j++){
        for(auto &[b,w]:g[j]){
            if(after[j]>before[b]+w){
                return {-1};
            }
        }
    }
    return before;
}

int main(){
    int N,E,s,a,b,c;
    cin>>N>>E>>s;
    vector<vector<pair<int,int>>> g(N);
    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        g[b].push_back({a,c});
    }
    for(auto &x:bellman_ford(g,s)){
        cout<<x<<" ";
    }
}
