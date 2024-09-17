#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,c=2;
    vector<long long> v = {0,1,3};
    while(v[v.size()-1] < 2e9){
        if (v.size()>v[c]){
            c++;
        }
        v.push_back(v[v.size()-1]+c);
    }
    cin>>n;
    while(n--){
        long long x;
        cin>>x;
        cout<<*(lower_bound(v.begin(),v.end(),x))<<"\n";
    }
}