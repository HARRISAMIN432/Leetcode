class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        costs.resize(n, vector<int>(n));
        dp.resize(n, -1);
        compute(nums, k);
        return f(0, nums);
    }

private:
    vector<vector<int>> costs;
    vector<int> dp;

    int f(int i, vector<int> &nums) {
        if(i == nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int j = i; j < nums.size(); j++) 
            ans = min(ans, costs[i][j] + f(j + 1, nums));
        return dp[i] = ans;
    }

    void compute(vector<int> &nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> mp;
            int elementsAfterTrim = 0;
            for(int j = i; j < nums.size(); j++) {
                mp[nums[j]]++;
                if(mp[nums[j]] == 2) elementsAfterTrim += 2;
                else if(mp[nums[j]] > 2) elementsAfterTrim++;
                costs[i][j] = k + elementsAfterTrim;
            }
        }
    }
};