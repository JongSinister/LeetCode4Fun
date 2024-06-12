#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=haystack.size(),n=needle.size();
        if (n==0) return 0;
        for(int i=0;i<h-n+1;i++){
            bool check=false;
            for(int j=0;j<n;j++){
                if(haystack[i+j]!=needle[j]){
                    check=true;
                    break;
                }
            }
            if (!check) return i;
        }
        return -1;
    }
};