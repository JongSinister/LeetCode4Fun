#include <bits/stdc++.h>

using namespace std;

void permu(int n,int len,vector<int> &sol,vector<bool> &used){
    if (len==n){
        for(auto &x : sol){
            cout<<x;
        }
        cout<<"\n";
    }else{
        for(int i=0;i<n;i++){
            if (used[i]==false){
                used[i]=true;
                sol[len]=i;
                permu(n,len+1,sol,used);
                used[i]=false;
            }
        }
    }
}

int main(){
    int test=3;
    vector<int> sol(test);
    vector<bool> used(test);
    permu(test,0,sol,used);
}