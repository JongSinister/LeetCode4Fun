#include <bits/stdc++.h>

using namespace std;

int mod(int a,int n,int k){
    if (n==1){
        return a%k;
    }
    if (n%2==0){
        int tmp = mod(a,n/2,k);
        return (tmp*tmp)%k;
    }else{
        int tmp = mod(a,n/2,k);
        return ((tmp*tmp)%k*a)%k;
    }
}

int main(){
    int a=2;
    int n=5;
    int k=7;
    cout<<mod(5281 ,2000000000, 1103);
}