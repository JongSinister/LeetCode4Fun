#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size(),n2=arr2.size(),c=0;
        vector<int> ans(n1);map<int,int> m;
        for(int i=0;i<n1;i++){
            m[arr1[i]]++;
        }
        for(int i=0;i<n2;i++){
            while(m[arr2[i]]--){
                ans[c]=arr2[i];
                c++;
            }
        }
        for(auto &x:m){
            while(x.second>0){
                x.second--;
                ans[c]=x.first;
                c++;
            }
        }
            return ans;
        }
};