#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &v,vector<int> &tmp,int left,int right,int mid){
    int bi = left; //index of B
    int ci = mid+1; //index of C
    for (int i = left; i<= right;i++) {
    if (ci > right) { 
        tmp[i] = v[bi++];
        continue;
    }
    if (bi > mid) {
        tmp[i] = v[ci++];
        continue;
    }
    tmp[i] = (v[bi] < v[ci]) ? v[bi++] : v[ci++];
    }
    for (int i = left; i<= right;i++){
        v[i] = tmp[i];
    }

}

void merge_sort(vector<int> &v,vector<int> &tmp,int left,int right){
    if (left >= right) return;
    int mid = (left+right)/2;
    merge_sort(v,tmp,left,mid);
    merge_sort(v,tmp,mid+1,right);
    merge(v,tmp,left,right,mid);
}

int main(){
    vector<int> v = {5,6,7,1,3,510,219};
    vector<int> tmp(v.size());
    merge_sort(v,tmp,0,v.size());
    for(auto &x:v){
        cout<<x<<" ";
    }
}