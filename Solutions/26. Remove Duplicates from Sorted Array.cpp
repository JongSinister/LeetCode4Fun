#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), last = 1, i = 0;
        while (true) {
            i++;
            if (i >= n)
                break;
            if (nums[i] != nums[i - 1]) {
                cout << nums[i - 1] << " " << nums[i] << "\n";
                nums[last] = nums[i];
                last++;
            }
        }
        return last;
    }
};