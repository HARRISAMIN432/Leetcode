class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pref = 0, ans = 0;
        for (int x : nums) {
            pref += x;
            if (mp.count(pref - k)) 
                ans += mp[pref - k];
            mp[pref]++;
        }
        return ans;
    }
};