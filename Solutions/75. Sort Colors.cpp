#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(),c=0;;map<int,int> m;
        for(int i=0;i<n;i++) m[nums[i]]++;
        for(auto &[a,b]:m){
            for(int i=0;i<b;i++){
                nums[i+c]=a;
            }
            c+=b;
        }
    }
};