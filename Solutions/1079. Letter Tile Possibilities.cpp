#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        set<string> all;
        map<string,int> mp;
        void sol(string &tiles, string s,int curr, map<string,int> mp2){
            if (curr >= tiles.size()) return;
            for (int i=0;i<tiles.size();i++){
                string a = "";a += tiles[i];string temp = s+tiles[i];
                if (all.find(temp) != all.end()){
                    continue;
                }
                mp2[a]++;
                bool check = false;
                for (auto &x: mp2){
                    if (x.second > mp[x.first]) check = true;
                }
                if (check){
                    mp2[a]--;
                    continue;
                }
                all.insert(temp);
                sol(tiles,temp,curr+1, mp2);
                mp2[a]--;
            }
        }
        int numTilePossibilities(string tiles) {
            sort(tiles.begin(), tiles.end());
            for (int i=0;i<tiles.size();i++){
                string temp = "";
                temp += tiles[i];
                mp[temp]++;
            }
            map<string,int> mp2;
            sol(tiles,"",0, mp2);
            return all.size();
        }
    };