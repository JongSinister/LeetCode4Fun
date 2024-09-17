#include <bits/stdc++.h>

using namespace std;

int getsum(vector<int> &s,int from, int to){
    return s[to] - s[from-1];
}

int mss(vector<int> &v, int start, int stop, vector<int> &s){
    if(start==stop) return v[start];

    int mid = (start+stop)/2;

    int r1 = mss(v, start, mid, s);
    int r2 = mss(v, mid+1, stop, s);

    int mxl = getsum(s, mid, mid);
    int mxr = getsum(s, mid+1, mid+1);

    //S[*][m] --> * = l to m
    for(int i=start; i<=mid; ++i){
        mxl = max(mxl, getsum(s, i, mid));
    }

    //S[m+1][*] --> * = m+1 to r
    for(int i=mid+1; i<=stop; ++i){
        mxr = max(mxr, getsum(s, mid+1, i));
    }

    int r3 = mxl + mxr;
    return max(max(r1, r2), r3);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n+1,0);
    vector<int> s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        s[i]=s[i-1]+v[i];
    }
    cout<<mss(v,1,n,s);
}