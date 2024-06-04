#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[ans] = nums[i];
                ans++;
            }
        }
        return ans;
    }
};