class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() & 1) {
            int ans = 0;
            for(int i = 0; i < nums.size() / 2; i++) ans += abs(nums[i] - nums[nums.size() / 2]);
            for(int i = nums.size() / 2 + 1; i < nums.size(); i++) ans += abs(nums[i] - nums[nums.size() / 2]);
            return ans;
        }
        else {
            int tmp = 0;
            for(int i = 0; i < nums.size() / 2; i++) tmp += abs(nums[i] - nums[nums.size() / 2]);
            for(int i = nums.size() / 2 + 1; i < nums.size(); i++) tmp += abs(nums[i] - nums[nums.size() / 2]);
            int tmp1 = 0;
            for(int i = 0; i < nums.size() / 2 - 1; i++) tmp1 += abs(nums[i] - nums[nums.size() / 2 - 1]);
            for(int i = nums.size() / 2; i < nums.size(); i++) tmp1 += abs(nums[i] - nums[nums.size() / 2 - 1]);
            return min(tmp, tmp1);
        }
    }
};