#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        for(long i=1;i<=x;i++){
            if(i*i==x) return i;
            if(i*i>x) return i-1; 
        }
        return x;
    }
};