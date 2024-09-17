#include <bits/stdc++.h>
using namespace std;

// ADJ VERTEX A (1-N)
vector<int> adj(int a,vector<vector<int>> &G){
    vector<int> ans;
    for(int i=1;i<=G.size();i++){
        if(i==a) continue;
        if(G[a][i] == 1) ans.push_back(i);
    }
    return ans;
}

// ADJ VERTEX A (0-N) && HANDLE CASE LOOP BETWEEN PREV VERTEX
vector<int> adj(int a,int prev,vector<vector<int>> &G){
    vector<int> ans;
    for(int i=0;i<G.size();i++){
        if(i==a||i==prev) continue;
        if(G[a][i]==1) ans.push_back(i);
    }
    return ans;
}

// DFS
void dfs(int a,vector<vector<int>> &G,vector<bool> &visited,vector<int> &from){
    visited[a]=true;
    for(auto &b : adj(a,G)){
        if(!visited[b]){
            from[b]=a;
            dfs(b,G,visited,from);
        }
    }
}

// DFS_STACK
void dfs_stack(int a,vector<vector<int>> &G,vector<bool> &visited,vector<int> &from){
    stack<int> s;
    s.push(a);
    visited[a]=true;
    while(!s.empty()){
        int u=s.top();
        s.pop();
        for(auto &b: adj(u,G)){
            if(!visited[b]){
                visited[b]=true;
                from[b]=u;
                s.push(b);
            }
        }
    }
}

//BFS_QUEUE
void bfs_queue(int a,vector<vector<int>> &G,vector<bool> &visited,vector<int> &from){
    queue<int> q;
    q.push(a);
    visited[a]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto &b:adj(u,G)){
            if(!visited[b]){
                visited[b]=true;
                from[b]=u;
                q.push(b);
            }
        }
    }
}


int main(){
    int n=7;
    vector<vector<int>> G(n+1,vector<int>(n+1));
    vector<bool> visited(n+1, false);
    vector<int> from(n+1,-1);
    G = {
    //   0 1 2 3 4 5 6 7
        {0,0,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0}, //1
        {0,0,0,1,0,0,0,0}, //2
        {0,0,0,0,0,0,0,0}, //3
        {0,0,1,0,0,1,0,0}, //4
        {0,0,0,1,0,0,1,0}, //5
        {0,0,1,0,0,0,0,0}, //6
        {0,0,0,0,0,0,1,0}  //7
    };
    //dfs(7,G,visited,from);
    //dfs_stack(7,G,visited,from);
    bfs_queue(7,G,visited,from);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<visited[i]<<" "<<from[i];
        cout<<"\n";
    }
}