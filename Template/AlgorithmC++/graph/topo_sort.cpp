#include <bits/stdc++.h>
using namespace std;

vector<int> topo_sort(vector<int> &deg,map<int,vector<int>> &g){
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<deg.size();i++){
        if(deg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        ans.push_back(u);
        for(auto &b:g[u]){
            deg[b]--;
            if(deg[b]==0) q.push(b);
        }
    }
    return ans;
}


int main(){
    int n,a,b;
    cin>>n;
    vector<int> deg(n,0);
    map<int,vector<int>> g;
    for(int i=0;i<n;i++) {g.emplace(i,vector<int>());}
    for(int i=0;i<n;i++){
        cin>>a;
        while(a--){
            cin>>b;
            deg[i]++;
            g[b].push_back(i);
        }
    }
    vector<int> ans=topo_sort(deg,g);
    for(auto &x:ans) cout<<x<<" ";
}