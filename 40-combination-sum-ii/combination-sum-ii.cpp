class Solution {
public:
    void helper(int i, vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j - 1]) continue;
            if(nums[j] > target) break;
            temp.push_back(nums[j]);
            helper(j + 1, nums, target - nums[j], temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, nums, target, temp, ans);
        return ans;
    }
};