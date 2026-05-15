class Solution {
public:
    bool check(vector<int> nums, int k, int target) {
        int n = nums.size();
        for(int i = 0; i + 1 < n; i++) {
            if(nums[i] != target) {
                if(k == 0) return false;
                nums[i] = target;
                nums[i + 1] *= -1;
                k--;
            }
        }
        return nums[n - 1] == target;
    }

    bool canMakeEqual(vector<int>& nums, int k) {
        return check(nums, k, 1) || check(nums, k, -1);
    }
};