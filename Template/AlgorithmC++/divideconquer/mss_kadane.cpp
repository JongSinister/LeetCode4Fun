#include <bits/stdc++.h>

using namespace std;

int mss(vector<int> &v){
    int max_global,max_current;
    max_global=max_current=v[0];
    for(int i=1;i<v.size();++i){
        max_current = max(v[i],max_current+v[i]);
        max_global = max(max_current,max_global);
    }
    return max_global;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<mss(v);
}