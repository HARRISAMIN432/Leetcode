class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> pref(nums.size() + 1, 0);
        for(int i = 1; i < pref.size(); i++) pref[i] += pref[i - 1] + nums[i - 1];
        int ans = 0;
        for(int i = 1; i < nums.size(); i++) 
            if((pref[i] - (pref[nums.size()] - pref[i])) % 2 == 0) ans++;
        return ans;
    }
};