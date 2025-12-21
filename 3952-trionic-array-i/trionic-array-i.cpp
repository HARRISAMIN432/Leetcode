class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1;
        if(nums[1] <= nums[0] || nums[nums.size() - 1] <= nums[nums.size() - 2]) return false;
        while(i < nums.size() && nums[i] > nums[i - 1]) i++;
        if(i == nums.size()) return false;
        while(i < nums.size() && nums[i] < nums[i - 1]) i++;
        while(i < nums.size() && nums[i] > nums[i - 1]) i++;
        if(i != nums.size()) return false;
        return true;
    }
};