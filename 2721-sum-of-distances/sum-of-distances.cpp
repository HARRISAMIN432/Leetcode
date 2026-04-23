class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        vector<long long> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
        for (auto it : mp) {
            vector<int> idx = it.second;
            if (idx.size() == 1) {
                ans[idx[0]] = 0;
                continue;
            }
            vector<long long> pref(idx.size(), idx[0]);
            for (int i = 1; i < idx.size(); i++)
                pref[i] = pref[i - 1] + idx[i];
            vector<long long> sums(idx.size());
            sums[0] = (pref[idx.size() - 1] - pref[0]) - 1LL * idx[0] * (idx.size() - 1);
            sums[idx.size() - 1] = 1LL * idx[idx.size() - 1] * (idx.size() - 1) - pref[idx.size() - 2];
            for (int i = 1; i < idx.size() - 1; i++) 
                sums[i] = (pref[idx.size()-1] - pref[i] - 1LL * idx[i] * (idx.size()-i-1)) + (1LL* idx[i] * i - pref[i - 1]);
            for (int i = 0; i < sums.size(); i++)
                ans[idx[i]] = sums[i];
        }
        return ans;
    }
};