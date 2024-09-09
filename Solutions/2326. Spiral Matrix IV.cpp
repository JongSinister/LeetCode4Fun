#include <bits/stdc++.h>
using namespace std;
 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    typedef pair<int,int> pii;    
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        vector<pii> move = {{0,1},{1,0},{0,-1},{-1,0}};
        int r=0,c=0,state=0;
        while(head) {
            ans[r][c]=head->val;
            head=head->next;
            int nr=r+move[state].first,nc=c+move[state].second;
            if(nr>=m||nr<0||nc>=n||nc<0||ans[nr][nc]!=-1) {
                state=(state+1)%4;
                nr=r+move[state].first,nc=c+move[state].second;
            }
            r=nr,c=nc;
        } 
        return ans;
    }
};
