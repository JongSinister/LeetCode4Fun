#include <bits/stdc++.h>

using namespace std;

void combi(int n,vector<int> &sol, int len){
    if(len == n){
        for(int i=0;i<n;i++){
            if (sol[i]==1){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }else{
        sol[len]=0;
        combi(n,sol,len+1);
        sol[len]=1;
        combi(n,sol,len+1);
    }
}

int main(){
    int test = 3;
    vector<int> sol(test,0);
    combi(test,sol,0);
}