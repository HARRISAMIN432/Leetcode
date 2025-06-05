class Solution {
public:
    void helper(int idx, int target, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp) {
        if(idx == nums.size() || target < 0) return;
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(i, target - nums[i], nums, ans, temp);
            temp.pop_back();
        }        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, target, candidates, ans, temp);
        return ans;
    }
};