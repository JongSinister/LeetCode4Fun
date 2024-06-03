#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxi=0;
        vector<char> v;
        while(r<s.size()){
            if(find(v.begin(),v.end(),s[r])!=v.end()){
                l++;
                r=l;
                v.clear();
            }
            v.push_back(s[r]);
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};