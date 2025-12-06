class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans = nums.size(), curr = nums[0];
        for(int &x : nums) (x < curr) ? ans-- :curr = x;
        return ans;
    }
};