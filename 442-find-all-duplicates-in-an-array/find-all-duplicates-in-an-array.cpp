class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int num : nums) m[num]++;
        for(const auto& [key, val] : m)
        if(val > 1)
            ans.push_back(key);
        return ans;
    }
};