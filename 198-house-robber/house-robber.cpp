class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2) return *max_element(nums.begin(), nums.end());
        int a = -1, b = -1, c = -1;
        a = nums[nums.size() - 1];
        b = max(nums[nums.size() - 1], nums[nums.size() - 2]);
        for(int i = nums.size() - 3; i >= 0; i--) {
            c = max(nums[i] + a, b);
            a = b;
            b = c;
        }
        return c;
    }
};