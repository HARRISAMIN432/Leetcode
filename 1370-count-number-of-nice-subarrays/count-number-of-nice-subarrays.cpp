class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int pref = 0, ans = 0;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                pref++;
                mp[pref] = i;
            }
        }
        mp[pref + 1] = nums.size();
        for (int i = k; i <= pref; i++) {
            int leftChoices  = mp[i - k + 1] - mp[i - k];
            int rightChoices = mp[i + 1] - mp[i];
            ans += leftChoices * rightChoices;
        }
        return ans;
    }
};