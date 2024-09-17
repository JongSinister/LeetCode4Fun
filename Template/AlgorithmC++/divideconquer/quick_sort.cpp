#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &v,int start,int stop){
    int pivot = v[start];

    int left = start-1;
    int right = stop+1;

    while(left<right){
        while(v[++left]<pivot){}

        while(v[--right]>pivot){}

        if (left>=right) return right;

        swap(v[left],v[right]);
    }

    return right;
}

void quick_sort(vector<int> &v,int start,int stop){
    if (start >= stop) return;
    
    int p = partition(v,start,stop);
    quick_sort(v,start,p);
    quick_sort(v,p+1,stop);
}

int main(){
    vector<int> v = {5,6,7,1,3,510,219};
    quick_sort(v,0,v.size());
    for(auto &x:v){
        cout<<x<<" ";
    }
}