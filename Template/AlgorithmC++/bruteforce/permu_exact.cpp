#include <bits/stdc++.h>

using namespace std;

void permu_exact(int n,int len,int k,vector<int> &sol,vector<bool> &used){
    if(len==k){
        for(int i=0;i<k;i++){
            cout<<sol[i];
        }
    cout<<"\n";
    }else{
        for(int i=0;i<n;i++){
            if (used[i]==false){
                used[i]=true;
                sol[len]=i;
                permu_exact(n,len+1,k,sol,used);
                used[i]=false;
            }
        }
    }
}

int main(){
    int test=4;
    int k=3;
    vector<int> sol(test);
    vector<bool> used(test);
    permu_exact(test,0,k,sol,used);
}