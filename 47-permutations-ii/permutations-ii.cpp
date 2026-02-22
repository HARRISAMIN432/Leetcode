class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> vis(nums.size(), false);
        set<vector<int>> dp;
        f(nums, tmp, ans, vis, dp);
        return ans;
    }

private:
    void f(vector<int> &nums, vector<int> &tmp, vector<vector<int>> &ans, vector<bool> &vis, set<vector<int>> &dp) {
        if(tmp.size() == nums.size()) {
            if(dp.find(tmp) == dp.end()) {
                ans.push_back(tmp);
                dp.insert(tmp);
            }
            return;
        } 
        for(int i = 0; i < nums.size(); i++) {
            if(!vis[i]) {
                tmp.push_back(nums[i]);
                vis[i] = true;
                f(nums, tmp, ans, vis, dp);
                vis[i] = false;
                tmp.pop_back();
            }
        }
    }
};