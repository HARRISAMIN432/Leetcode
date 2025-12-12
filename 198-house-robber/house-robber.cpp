class Solution {
public:
   int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    int a = nums[n-1], b = max(nums[n-2], nums[n-1]);
    for (int i = n - 3; i >= 0; i--) {
        int c = max(nums[i] + a, b);
        a = b;
        b = c;
    }
    return b;
}
};