#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int c = 0, p = 0, n = s.size(), m = t.size();
        while (c < n) {
            if (p >= m) {
                return 0;
            }
            if (s[c] == t[p]) {
                c++;
                p++;
                continue;
            }
            c++;
        }
        return m - p;
    }
};