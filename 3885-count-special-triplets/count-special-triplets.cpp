class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]].push_back(i);
        const int MOD = 1'000'000'007;
        long long ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            int target = nums[j] * 2;
            if (!m.count(target)) continue;
            auto &vec = m[target];
            auto it = lower_bound(vec.begin(), vec.end(), j);
            long long left = it - vec.begin();       
            long long right = vec.end() - upper_bound(vec.begin(), vec.end(), j);
            ans = (ans + left * right) % MOD;
        }

        return ans;
    }
};
