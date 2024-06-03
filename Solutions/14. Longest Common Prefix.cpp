#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            bool check=false;
            for(int j=1;j<n;j++){
                if(strs[j][i]!=strs[j-1][i]){
                    check=true;
                    break;
                }
            }
            if(check) break;
            ans+=strs[0][i];
        }
        return ans;
    }
};