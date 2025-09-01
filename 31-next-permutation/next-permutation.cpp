class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int lidx = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                lidx = i;
                break;
            }
        }
        if (lidx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int ridx = -1;
        for (int i = n - 1; i > lidx; i--) {
            if (nums[i] > nums[lidx]) {
                ridx = i;
                break;
            }
        }
        swap(nums[lidx], nums[ridx]);
        reverse(nums.begin() + lidx + 1, nums.end());
    }
};
