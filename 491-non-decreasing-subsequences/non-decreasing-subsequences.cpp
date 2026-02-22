class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        set<vector<int>> dp;
        f(0, nums, temp, ans, dp);
        return ans;
    }

private:
    void f(int i, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, set<vector<int>> &dp) {
        if(i == nums.size()) {
            if(temp.size() >= 2 && dp.find(temp) == dp.end()) {
                ans.push_back(temp);
                dp.insert(temp);
            }
            return;
        }
        if (temp.empty() || (!temp.empty() && nums[i] >= temp.back())) {
            temp.push_back(nums[i]);
            f(i + 1, nums, temp, ans, dp);
            temp.pop_back();
        }
        f(i + 1, nums, temp, ans, dp);
    }
};