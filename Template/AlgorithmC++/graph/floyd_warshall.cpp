#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void floyd_warshall(vector<vector<int>>& dist){
    int n=dist.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,k,v,a,b,c,ans=INF;
    cin>>n>>m>>k>>v;
    vector<int> start(k);
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for(int i=0;i<k;i++) cin>>start[i];
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        dist[a][b]=c;
    }
    for(int i=0;i<n;i++) dist[i][i]=0;
    floyd_warshall(dist);
    for(auto &x:start){
        ans=min(ans,dist[x][v]);
    }
    cout<<ans;
}
