#include <bits/stdc++.h>

using namespace std;

int bsearch(vector<int > &v, int k, int start, int stop){
    if (start == stop){
        if (v[start] == k) return start;
        return -1;
    }
    int m = (start + stop)/2;
    if (v[m] >= k)
        return bsearch(v, k, start, m);
    else
        return bsearch(v, k, m + 1, stop);
}

int main(){
    vector<int> test = {10,13,14,14,14,15,16,16,18,200};
    cout <<bsearch(test, 11, 0, test.size());
}
