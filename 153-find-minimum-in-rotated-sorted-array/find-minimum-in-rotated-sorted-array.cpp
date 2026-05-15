class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), ans = nums[0], low = 0, high = n - 1, mid;
        while(low <= high) {
            mid = (low + high) >> 1;
            if(nums[mid] >= nums[0]) low = mid + 1;
            else high = mid - 1;
            if(nums[mid] < ans) ans = nums[mid];
        }
        return ans;
    }
};