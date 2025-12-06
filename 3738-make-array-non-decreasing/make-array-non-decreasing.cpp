class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans = nums.size(), curr = nums[0];
        for(int i = 1; i < nums.size(); i++) (nums[i] < curr) ? ans-- :curr = nums[i];
        return ans;
    }
};