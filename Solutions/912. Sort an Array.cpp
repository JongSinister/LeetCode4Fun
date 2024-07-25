#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int,int> m;int n=nums.size();vector<int> ans;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto x:m){
            for(int i=0;i<x.second;i++){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};