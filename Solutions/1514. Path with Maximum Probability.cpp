#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    double maxProbability(int n,vector<vector<int>>& edges,vector<double>& succProb,int start_node,int end_node){
        vector<vector<pair<int,double>>> G(n);
        for(int i=0;i<edges.size();++i){
            int s=edges[i][0],e=edges[i][1];
            double w=succProb[i];
            G[s].push_back({e,w});
            G[e].push_back({s,w});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n,0.0);
        dist[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto [T,u]=pq.top();pq.pop();
            if(T<dist[u])continue;
            for(auto [b,w]:G[u]){
                if(dist[b]<dist[u]*w){
                    dist[b]=dist[u]*w;
                    pq.push({dist[b],b});
                }
            }
        }
        return dist[end_node];
    }
};
