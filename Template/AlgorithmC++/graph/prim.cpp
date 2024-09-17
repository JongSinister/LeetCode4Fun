#include <bits/stdc++.h>
using namespace std;
int prim(vector<vector<pair<int,int>>> &G) {
    int total_cost = 0;
    vector<int> cost(G.size(), 1001);
    vector<bool> visited(G.size(), false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    cost[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        total_cost += cost[u];
        for (auto &[w, v] : G[u]) {
            if (!visited[v] && cost[v] > w) {
                cost[v] = w;
                pq.push({w, v});
            }
        }
    }
    return total_cost;
}

int main() {
    int n,tmp;
    cin>>n;
    vector<vector<pair<int,int>>> G(n);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cin>>tmp;
            G[i].push_back({tmp,j});
            G[j].push_back({tmp,i});
        }
    }
    cout<<prim(G);
}