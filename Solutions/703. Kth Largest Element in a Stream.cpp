#include <bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    int k;
    vector<int> data;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++){
            data.push_back(nums[i]);
        }
        sort(data.begin(),data.end());
    }
    
    int add(int val) {
        data.insert(lower_bound(data.begin(),data.end(),val),val);
        return data[data.size()-k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */