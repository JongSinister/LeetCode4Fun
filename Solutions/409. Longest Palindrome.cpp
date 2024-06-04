#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        map<char, int> m;
        for (auto& x : s) {
            m[x]++;
        }
        for (auto& [x, y] : m) {
            if (y > 1) {
                if (y % 2 == 0) {
                    ans += y;
                } else {
                    ans += y - 1;
                }
            }
        }
        if (ans < s.size())
            ans += 1;
        return ans;
    }
};