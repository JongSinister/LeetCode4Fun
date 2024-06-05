#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < n; i++) {
            for (auto& c : words[i]) {
                if (m.find(c) == m.end()) {
                    m[c] = vector<int>(n, 0);
                }
                m[c][i]++;
            }
        }
        for (auto& c : m) {
            int minelem = *min_element(c.second.begin(), c.second.end());
            if (minelem == 0)
                continue;
            for (int i = 0; i < minelem; i++) {
                string bruh = "";
                bruh = c.first;
                ans.push_back(bruh);
            }
        }
        return ans;
    }
};