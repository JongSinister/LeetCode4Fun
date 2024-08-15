#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> m={{5,0},{10,0},{20,0}};
        for(auto &x:bills){
            if(x==10){
                if(m[5]<=0){
                    return false;
                }
                m[5]--;
            }else if(x==20){
                if(m[10]>0 && m[5]>0){
                    m[10]--;m[5]--;
                }else if(m[5]>=3){
                    m[5]-=3;
                }else{
                    return false;
                }
            }
            m[x]++;
        }
        return true;
    }
};