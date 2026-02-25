class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, ans = 2;
        for(int i = 1; i < nums.size(); i++) {
            if(i - left <= 1) continue;
            if(nums[i - 1] + nums[i - 2] != nums[i]) {
                ans = max(ans, i - left);
                left = i - 1;
            }
        }
        return max(ans, (int)nums.size() - left);
    }
};