#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mod_map;
        mod_map[0] = -1;
        int prefix_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            int mod = prefix_sum % k;
            if (mod_map.find(mod) != mod_map.end()) {
                if (i - mod_map[mod] > 1) {
                    return true;
                }
            } else {
                mod_map[mod] = i;
            }
        }
        return false;
    }
};