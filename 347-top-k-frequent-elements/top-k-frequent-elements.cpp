class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) m[nums[i]]++;
        vector<pair<int, int>> a;
        for(auto it : m) a.push_back({it.second, it.first});
        sort(a.rbegin(), a.rend());
        vector<int> ans(k);
        for(int i = 0; i < k; i++) ans[i] = a[i].second;
        return ans;
    }
};