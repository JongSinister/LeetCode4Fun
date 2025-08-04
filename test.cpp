#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int n=s.size();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]) return false;
    }
    return true;
}

int main(){
    string s="babad ";
    int n=s.size();
    string ans="";
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            string sub=s.substr(i,j);
            if(isPalindrome(sub) && sub.size()>ans.size()){
                ans=sub;
            }
        }
    }
    cout<<ans;
}